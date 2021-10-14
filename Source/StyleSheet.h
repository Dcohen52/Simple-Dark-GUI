/*
  ==============================================================================

    StyleSheet.h
    Created: 11 Oct 2021 6:55:42pm
    Author:  Dekel's Studio

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

namespace juce {


    class CustomLNF : public juce::LookAndFeel_V4
    {
    public:
        void drawRotarySlider(Graphics &, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider &);

    };

}