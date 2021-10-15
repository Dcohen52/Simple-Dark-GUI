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
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

TopBar::~TopBar()
{
}

void TopBar::paint (juce::Graphics& g)
{
    // Background
    g.fillAll (juce::Colours::transparentBlack);

    // Presets section
    g.setColour(juce::Colour(0xff000000));
    auto cornerSize = 15.0f;
    auto bounds = getLocalBounds().toFloat().reduced(0.5f, 0.5f);

    g.setOpacity(0.1f);
    juce::Path path;
    path.addRoundedRectangle(bounds.getX() / 3.5, bounds.getY() / 2,
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
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
