/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

static juce::String thresholdValueToText(float value) { 
    return juce::String(value, 2); 
}

static float thresholdTextToValue(const juce::String& text) { 
    return text.getFloatValue(); 
}

static juce::String midiNoteValueToText(float value) { 
    return juce::String(value, 0); 
}

static float midiNoteTextToValue(const juce::String& text) { 
    return text.getFloatValue(); 
}

static juce::String releaseValueToText(float value) {
    return juce::String(value, 0);
}

static float releaseTextToValue(const juce::String& text) {
    return text.getFloatValue();
}

static juce::String manualTrigValueToText(float value) { 
    return juce::String(value, 0); 
}

static float manualTrigTextToValue(const juce::String& text) { 
    return text.getFloatValue(); 
}

juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout() {
    using Parameter = juce::AudioProcessorValueTreeState::Parameter;

    std::vector<std::unique_ptr<Parameter>> parameters;

    parameters.push_back(std::make_unique<Parameter>(   juce::String("threshold"), juce::String("Threshold"), juce::String(),
                                                        juce::NormalisableRange<float>(0.0f, 1.0f),    //min, max, step, skew
                                                        0.15f, thresholdValueToText, thresholdTextToValue));//default value

    parameters.push_back(std::make_unique<Parameter>(   juce::String("midi_note"), juce::String("Midi Note"), juce::String(),
                                                        juce::NormalisableRange<float>(0.0f, 127.0f, 1.0f),    //min, max, step, skew
                                                        64.0f, midiNoteValueToText, midiNoteTextToValue));//default value

    parameters.push_back(std::make_unique<Parameter>(   juce::String("release"), juce::String("Release"), juce::String(),
                                                        juce::NormalisableRange<float>(0.0f, 1000.0f, 25.0f),    //min, max, step, skew
                                                        100.0f, releaseValueToText, releaseTextToValue));//default value

    parameters.push_back(std::make_unique<Parameter>(   juce::String("manual_trig"), juce::String("Manual Trig"), juce::String(),
                                                        juce::NormalisableRange<float>(0.0f, 1.0f, 1.0f),    //min, max, step, skew
                                                        0.0f, manualTrigValueToText, manualTrigTextToValue));//default value

    return { parameters.begin(), parameters.end() };
}

//==============================================================================
TriggerAudioProcessor::TriggerAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
#endif
    parameters(*this, nullptr, juce::Identifier(JucePlugin_Name), createParameterLayout())
{
    /*  On garde une référence directe aux valeurs brutes des paramètres afin d'avoir un accès rapide dans la méthode processBlock. */
    thresholdParameter = parameters.getRawParameterValue("threshold");
    midiNoteParameter = parameters.getRawParameterValue("midi_note");
    releaseParameter = parameters.getRawParameterValue("release");
    manualTrigParameter = parameters.getRawParameterValue("manual_trig");
}

TriggerAudioProcessor::~TriggerAudioProcessor()
{
}

//==============================================================================
const juce::String TriggerAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool TriggerAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TriggerAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool TriggerAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double TriggerAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TriggerAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int TriggerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TriggerAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String TriggerAudioProcessor::getProgramName (int index)
{
    return {};
}

void TriggerAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void TriggerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    currentSampleRate = sampleRate;

    //trigsleeptime = static_cast<int>(100 / 1000 * sampleRate); // 100 ms / 1000 ms = ? samples / sample rate
    timeSinceTrig = static_cast<int>(*releaseParameter) + 1;
    audioTrig = false;
}

void TriggerAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool TriggerAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void TriggerAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    auto numSamples = buffer.getNumSamples();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());

    float threshold = *thresholdParameter;
    int midiNote = static_cast<int>(*midiNoteParameter);
    int trigSleeptime = static_cast<int>((*releaseParameter / 1000.0) * static_cast<float>(currentSampleRate));
    int trigStateSleeptime = static_cast<int>(0.05 * static_cast<float>(currentSampleRate));
    float manuallyTrigged = *manualTrigParameter;

    // MANUAL TRIG
    if (manuallyTrigged > 0.5 && manuallyTrigged_previous < 0.5) {
        midiMessages.addEvent(juce::MidiMessage::noteOn(1, midiNote, (juce::uint8)127), 0);
        midiMessages.addEvent(juce::MidiMessage::noteOff(1, midiNote), (numSamples - 1));
    }
    manuallyTrigged_previous = manuallyTrigged;

    // AUDIO TRIG 
    timeSinceTrig += numSamples;

    // Reset the audioTrigState parameter
    if (timeSinceTrig > trigStateSleeptime) {
        audioTrigState = false;
    }

    for (int channel = 0; channel < totalNumInputChannels; ++channel) {

        auto bufferRMS = buffer.getRMSLevel(channel, 0, numSamples);
        audioTrig = bufferRMS > threshold ? true : false;
    }

    if (audioTrig && timeSinceTrig > trigSleeptime) {
        midiMessages.addEvent(juce::MidiMessage::noteOn(1, midiNote, (juce::uint8)127), 0);
        midiMessages.addEvent(juce::MidiMessage::noteOff(1, midiNote), (numSamples - 1));
        audioTrigState = true;
        timeSinceTrig = 0;
    }
//    else {
//        audioTrigState = false;
//    }
}

//==============================================================================
bool TriggerAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* TriggerAudioProcessor::createEditor()
{
    return new TriggerAudioProcessorEditor (*this, parameters);
}

//==============================================================================
void TriggerAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    auto state = parameters.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void TriggerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
            parameters.replaceState(juce::ValueTree::fromXml(*xmlState));
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TriggerAudioProcessor();
}
