/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class TriggerAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    TriggerAudioProcessor();
    ~TriggerAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation(juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    //==============================================================================
    std::atomic<bool> audioTrigState;

private:
    //==============================================================================
    juce::AudioProcessorValueTreeState parameters;

    double currentSampleRate;

    std::atomic<float> *thresholdParameter = nullptr;
    std::atomic<float> *midiNoteParameter = nullptr;
    std::atomic<float> *releaseParameter = nullptr;
    std::atomic<float> *manualTrigParameter = nullptr;

    std::atomic<float> manuallyTrigged_previous;

    //std::atomic<int> trigSleeptime;
    std::atomic<int> timeSinceTrig;
    std::atomic<bool> audioTrig;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TriggerAudioProcessor)
};
