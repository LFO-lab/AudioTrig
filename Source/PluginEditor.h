/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "CustomLookAndFeel.h"

//==============================================================================
/**
*/
class TriggerAudioProcessorEditor  :    public juce::AudioProcessorEditor,
                                        public juce::Timer
{
public:
    TriggerAudioProcessorEditor (TriggerAudioProcessor&, juce::AudioProcessorValueTreeState& vts);
    ~TriggerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void toggleBack();
    void timerCallback() override;
    // void audioTrigVisualisation();

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TriggerAudioProcessor& audioProcessor;

    CustomLookAndFeel lookAndFeel;

    /*  Référence à l'arbre des paramètres dans l'éditeur graphique.    */
    juce::AudioProcessorValueTreeState& valueTreeState;

    juce::Slider threshold;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> thresholdAttachment;

    juce::Slider midiNote;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> midiNoteAttachment;

    juce::Slider release;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> releaseAttachment;

    juce::ToggleButton manualTrig;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> manualTrigAttachment;

    std::atomic<bool> previousAudioTrigState;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TriggerAudioProcessorEditor)
};
