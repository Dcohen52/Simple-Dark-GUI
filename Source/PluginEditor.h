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
class PluginTryout2AudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    PluginTryout2AudioProcessorEditor (PluginTryout2AudioProcessor&);
    ~PluginTryout2AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PluginTryout2AudioProcessor& audioProcessor;

    juce::Image backgroundImage;

    juce::CustomLNF myCustomLNF;
    juce::Slider fatness;
    juce::Slider glitter;
    juce::Slider medbell;
    juce::Slider cutoff;
    TopBar topBar;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginTryout2AudioProcessorEditor)
};
