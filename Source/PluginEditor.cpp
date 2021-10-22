/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DDLAudioProcessorEditor::DDLAudioProcessorEditor (DDLAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 400);

    auto& params = processor.getParameters();
    juce::AudioParameterFloat* dryWetParameter = (juce::AudioParameterFloat*) params.getUnchecked(0);
    mDryWetSlider.setBounds(0, 100, 150, 150);
    mDryWetSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    mDryWetSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 30);
    mDryWetSlider.setRange(dryWetParameter->range.start, dryWetParameter->range.end);
    mDryWetSlider.setValue(*dryWetParameter);
    mDryWetSlider.setTextValueSuffix(" %");
    
    addAndMakeVisible(mDryWetSlider);
    
    
    mDryWetSlider.onValueChange = [this, dryWetParameter] {*dryWetParameter = mDryWetSlider.getValue(); };
    mDryWetSlider.onDragStart = [dryWetParameter] {dryWetParameter->beginChangeGesture(); };
    mDryWetSlider.onDragEnd = [dryWetParameter] {dryWetParameter->endChangeGesture(); };

    juce::AudioParameterFloat* feedbackParameter = (juce::AudioParameterFloat*) params.getUnchecked(1);

    mFeedbackSlider.setBounds(200, 100, 150, 150);
    mFeedbackSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    mFeedbackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 30);
    mFeedbackSlider.setRange(feedbackParameter->range.start, feedbackParameter->range.end);
    mFeedbackSlider.setValue(*feedbackParameter);
    mFeedbackSlider.setTextValueSuffix(" %");
    addAndMakeVisible(mFeedbackSlider);

    mFeedbackSlider.onValueChange = [this, feedbackParameter] {*feedbackParameter = mFeedbackSlider.getValue(); };
    mFeedbackSlider.onDragStart = [feedbackParameter] {feedbackParameter->beginChangeGesture(); };
    mFeedbackSlider.onDragEnd = [feedbackParameter] {feedbackParameter->endChangeGesture(); };

    juce::AudioParameterFloat* delayTimeParameter = (juce::AudioParameterFloat*) params.getUnchecked(2);

    mDelayTimeSlider.setBounds(400, 100, 150, 150);
    mDelayTimeSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    mDelayTimeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 30);
    mDelayTimeSlider.setRange(delayTimeParameter->range.start, delayTimeParameter->range.end);
    mDelayTimeSlider.setValue(*delayTimeParameter);
    mDelayTimeSlider.setTextValueSuffix(" S");
    addAndMakeVisible(mDelayTimeSlider);

    mDelayTimeSlider.onValueChange = [this, delayTimeParameter] {*delayTimeParameter = mDelayTimeSlider.getValue(); };
    mDelayTimeSlider.onDragStart = [delayTimeParameter] {delayTimeParameter->beginChangeGesture(); };
    mDelayTimeSlider.onDragEnd = [delayTimeParameter] {delayTimeParameter->endChangeGesture(); };



}

DDLAudioProcessorEditor::~DDLAudioProcessorEditor()
{
}

//==============================================================================
void DDLAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void DDLAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
