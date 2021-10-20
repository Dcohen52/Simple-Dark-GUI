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
    juce::Image normalButton1 = juce::ImageCache::getFromMemory(BinaryData::nextpreset_png, BinaryData::nextpreset_pngSize);
    juce::Image overButton1 = juce::ImageCache::getFromMemory(BinaryData::nextpreset_png, BinaryData::nextpreset_pngSize);
    juce::Image downButton1 = juce::ImageCache::getFromMemory(BinaryData::nextpreset_png, BinaryData::nextpreset_pngSize);
    nextPreset.setImages(false, false, true, normalButton1, 1.0f, {}, overButton1, 1.0f, {}, downButton1, 1.0f, {});
    addAndMakeVisible(nextPreset);

    juce::Image normalButton2 = juce::ImageCache::getFromMemory(BinaryData::backpreset_png, BinaryData::backpreset_pngSize);
    juce::Image overButton2 = juce::ImageCache::getFromMemory(BinaryData::backpreset_png, BinaryData::backpreset_pngSize);
    juce::Image downButton2 = juce::ImageCache::getFromMemory(BinaryData::backpreset_png, BinaryData::backpreset_pngSize);
    backPreset.setImages(false, false, true, normalButton2, 1.0f, {}, overButton2, 1.0f, {}, downButton2, 1.0f, {});
    addAndMakeVisible(backPreset);
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
    nextPreset.setBounds(getWidth() - 309, getHeight() / 2 - 6, 11, 11);
    backPreset.setBounds(getWidth() / 2 - 110, getHeight() / 2 - 6, 11, 11);
}
