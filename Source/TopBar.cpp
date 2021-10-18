/*
  ==============================================================================

    TopBar.cpp
    Created: 11 Oct 2021 8:38:05pm
    Author:  Dekel's Studio

  ==============================================================================
*/

#include <JuceHeader.h>
#include "TopBar.h"

//==============================================================================
TopBar::TopBar()
{
}

TopBar::~TopBar()
{
}

void TopBar::paint (juce::Graphics& g)
{
    // Background
    g.fillAll (juce::Colours::transparentBlack);

    // Presets section
    g.setColour(juce::Colour(0xffffffff));
    auto cornerSize = 15.0f;
    auto bounds = getLocalBounds().toFloat().reduced(0.5f, 0.5f);

    g.setOpacity(0.05f);
    juce::Path path;
    path.addRoundedRectangle(283.0f, bounds.getY() / 2,
        bounds.getWidth() / 3.5, bounds.getHeight(),
        cornerSize, cornerSize);

    g.fillPath(path);
    g.setColour (juce::Colour(0xffffffff));
    g.setFont (14.0f);
    g.drawText ("Default", getLocalBounds(),
                juce::Justification::centred, true);

}

void TopBar::resized()
{
    
}
