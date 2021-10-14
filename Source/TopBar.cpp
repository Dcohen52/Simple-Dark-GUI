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
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (juce::Colours::transparentBlack);   // clear the background

    g.setColour (juce::Colours::transparentBlack);
    // g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour(juce::Colours::black);
    
    // g.fillRoundedRectangle(getLocalBounds().toFloat(), 15.0f);

    auto cornerSize = 15.0f;
    auto bounds = getLocalBounds().toFloat().reduced(0.5f, 0.5f);

    juce::Path path;
    path.addRoundedRectangle(300.f, bounds.getY(),
        bounds.getWidth() / 4, bounds.getHeight(),
        cornerSize, cornerSize);

    g.fillPath(path);
    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("Default", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text

}

void TopBar::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
