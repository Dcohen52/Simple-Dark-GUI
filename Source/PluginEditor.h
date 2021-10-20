/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "StyleSheet.h"
#include "TopBar.h"

//==============================================================================
/**
*/
class DarkGUIAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    DarkGUIAudioProcessorEditor (DarkGUIAudioProcessor&);
    ~DarkGUIAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:

    DarkGUIAudioProcessor& audioProcessor;

    juce::Image backgroundImage;

    juce::CustomLNF myCustomLNF;
    juce::Slider dial1;
    juce::Slider dial2;
    juce::Slider dial3;
    juce::Slider dial4;
    TopBar topBar;
    juce::ImageButton moreButton;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DarkGUIAudioProcessorEditor)
};
