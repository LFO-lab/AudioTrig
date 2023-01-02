/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TriggerAudioProcessorEditor::TriggerAudioProcessorEditor (  TriggerAudioProcessor& p,
                                                            juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p), valueTreeState(vts)
{
    Timer::startTimerHz(60);

    // This is where our plugin’s editor size is set.
    setSize (750, 250);

    setLookAndFeel(&lookAndFeel);

    // THRESHOLD
    // these define the parameters of our slider object
    threshold.setSliderStyle(juce::Slider::LinearBar);
    threshold.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    threshold.setPopupDisplayEnabled(true, false, this);
    threshold.setTextValueSuffix("");
    // this function adds the slider to the editor
    addAndMakeVisible(&threshold);
    /*  On attache le slider a l'arbre de paramètres. */
    thresholdAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "threshold", threshold));

    // MIDI NOTE
    // these define the parameters of our slider object
    midiNote.setSliderStyle(juce::Slider::LinearBar);
    //midiNote.setRange(0.0, 127.0, 1.0);
    midiNote.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    midiNote.setPopupDisplayEnabled(true, false, this);
    midiNote.setTextValueSuffix("");
    //midiNote.setValue(1.0);
    // this function adds the slider to the editor
    addAndMakeVisible(&midiNote);
    /*  On attache le slider a l'arbre de paramètres. */
    midiNoteAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "midi_note", midiNote));

    // RELEASE TIME
    // these define the parameters of our slider object
    release.setSliderStyle(juce::Slider::LinearBar);
    release.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    release.setPopupDisplayEnabled(true, false, this);
    release.setTextValueSuffix("");
    // this function adds the slider to the editor
    addAndMakeVisible(&release);
    /*  On attache le slider a l'arbre de paramètres. */
    releaseAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "release", release));

    // MANUAL TRIG
    manualTrig.setButtonText("");
    manualTrig.onStateChange = [this] { toggleBack(); };
    addAndMakeVisible(&manualTrig);
    manualTrigAttachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment(valueTreeState, "manual_trig", manualTrig));
}

TriggerAudioProcessorEditor::~TriggerAudioProcessorEditor()
{
    Timer::stopTimer();
}

//==============================================================================
void TriggerAudioProcessorEditor::paint (juce::Graphics& g)
{
    // Background Color = (75, 79, 77)
    // Slider Color     = (146, 146, 146)
    // Trig Color       = (113, 192, 249)
    // Text Color       = (255, 255, 255)

    // Background color
    g.fillAll(juce::Colour(75, 79, 77));
    
    int pad = 20;
    juce::Rectangle<int> left_rect(pad, pad, getWidth()/3.0 - (pad*2), getHeight() - pad*2);
    juce::Rectangle<int> right_rect(getWidth()/3.0 + pad, pad, getWidth()/2.0, getHeight() - pad*2);

    g.setColour(juce::Colours::white);

    g.setFont(juce::Font("helvetica neue", 30.0f, juce::Font::bold));
    g.drawFittedText("AUDIOTRIG", left_rect, juce::Justification::topLeft, 1);

    g.setFont(juce::Font("helvetica neue", 19.0f, juce::Font::plain));
    g.drawFittedText("Sends a MIDI note when the audio input volume pass beyond the threshold.", left_rect, juce::Justification::centredLeft, 3);

    g.setFont(juce::Font("helvetica neue", 19.0f, juce::Font::plain));
    g.drawFittedText("THRESHOLD", right_rect, juce::Justification::topLeft, 2);
    g.drawFittedText("MIDI NOTE",                   getWidth()/3.0 + pad, (getHeight()-pad*2) * 0.33+pad, 150, 50, juce::Justification::topLeft, 2);
    g.drawFittedText("HOLD\n[ms between trigs]",    getWidth()/3.0 + pad, (getHeight()-pad*2) * 0.66, 150, 50, juce::Justification::topLeft, 2);
    g.drawFittedText("TRIG", right_rect, juce::Justification::bottomLeft, 2);

    // Rectangle separator
    g.setColour(juce::Colour(146, 146, 146));
    g.fillRect(getWidth()/3.0, pad, 1, getHeight() - (pad*2.0));

}

void TriggerAudioProcessorEditor::resized()
{
    int pad = 20;
    int slider_height = 20;
    int left = getWidth() / 1.6;

    // sets the position and size of the slider with arguments (x, y, width, height)
    threshold.setBounds (getWidth() / 1.8, (getHeight() - pad * 2) * 0.00 + pad, getWidth() / 2.5, slider_height);
    midiNote.setBounds  (getWidth() / 1.8, (getHeight() - pad * 2) * 0.33 + pad, getWidth() / 2.5, slider_height);
    release.setBounds   (getWidth() / 1.8, (getHeight() - pad * 2) * 0.66 + pad, getWidth() / 2.5, slider_height);
    manualTrig.setBounds(getWidth() / 1.8, (getHeight() - pad * 2) * 1.00 + pad - 19, getWidth() / 2.5, slider_height);
}

void TriggerAudioProcessorEditor::toggleBack()
{
    if (manualTrig.isDown() == true) {
        manualTrig.setToggleState(true, true);
    }
    else {
        manualTrig.setToggleState(false, true);
    }
}

void TriggerAudioProcessorEditor::timerCallback()
{
    bool audioTrigState = static_cast<bool>(audioProcessor.audioTrigState);
    
    if (audioTrigState != previousAudioTrigState) {
        if (audioTrigState == true) {
            manualTrig.setToggleState(true, false);
        }
        if (audioTrigState == false) {
            manualTrig.setToggleState(false, false);
        }
    }

    previousAudioTrigState = audioTrigState;
}
