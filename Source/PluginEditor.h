/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class DDLAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    DDLAudioProcessorEditor (DDLAudioProcessor&);
    ~DDLAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:

    juce::Slider mDryWetSlider;
    juce::Slider mFeedbackSlider;
    juce::Slider mDelayTimeSlider;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DDLAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DDLAudioProcessorEditor)
};
