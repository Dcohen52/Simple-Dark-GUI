/*
  ==============================================================================

    TopBar.h
    Created: 11 Oct 2021 8:38:05pm
    Author:  Dekel's Studio

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class TopBar  : public juce::Component
{
public:
    TopBar();
    ~TopBar() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::ImageButton nextPreset;
    juce::ImageButton backPreset;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TopBar)
    
};
