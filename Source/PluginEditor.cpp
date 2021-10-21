/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <ctime>

//==============================================================================
DarkGUIAudioProcessorEditor::DarkGUIAudioProcessorEditor (DarkGUIAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    juce::LookAndFeel::setDefaultLookAndFeel(&myCustomLNF);

    backgroundImage = juce::ImageCache::getFromMemory(BinaryData::background_wlabels_png, BinaryData::background_wlabels_pngSize);
    
    dial1.setComponentID("DIAL1");
    dial1.setTitle("Dial 1");
    dial1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    dial1.setRange(0.0f, 100.0f);
    dial1.setValue(10.0f);
    dial1.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, 0, 0, 0);
    addAndMakeVisible(dial1);

    dial2.setComponentID("DIAL2");
    dial2.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    dial2.setRange(0.0f, 100.0f);
    dial2.setValue(25.0f);
    dial2.setTextBoxStyle(juce::Slider::NoTextBox, true, 100, 25);
    addAndMakeVisible(dial2);

    dial3.setComponentID("DIAL3");
    dial3.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    dial3.setRange(0.0f, 100.0f);
    dial3.setValue(50.0f);
    dial3.setTextBoxStyle(juce::Slider::NoTextBox, true, 100, 25);
    addAndMakeVisible(dial3);

    dial4.setComponentID("DIAL4");
    dial4.setTitle("Dial 4");
    dial4.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    dial4.setRange(0.0f, 100.0f);
    dial4.setValue(80.0f);
    dial4.setTextBoxStyle(juce::Slider::NoTextBox, true, 100, 25);

    addAndMakeVisible(dial4);
    addAndMakeVisible(topBar);
    setSize (800, 300);

    juce::Image normalButton = juce::ImageCache::getFromMemory(BinaryData::more_small_png, BinaryData::more_small_pngSize);
    juce::Image overButton = juce::ImageCache::getFromMemory(BinaryData::more_small_png, BinaryData::more_small_pngSize);
    juce::Image downButton = juce::ImageCache::getFromMemory(BinaryData::more_small_png, BinaryData::more_small_pngSize);
    moreButton.setImages(false, false, true, normalButton, 1.0f, {}, overButton, 1.0f, {}, downButton, 1.0f, {});
    addAndMakeVisible(moreButton);
}

DarkGUIAudioProcessorEditor::~DarkGUIAudioProcessorEditor()
{
    juce::LookAndFeel::setDefaultLookAndFeel(nullptr);
}

//==============================================================================
void DarkGUIAudioProcessorEditor::paint (juce::Graphics& g)
{
    // Background photo
    g.drawImage(backgroundImage, getLocalBounds().toFloat());

    // Date-Time
    time_t now = time(0);
    char* dt = ctime(&now);

    // Logo
    g.setColour(juce::Colour(0xff444444));
    g.setFont(12);
    g.drawText(dt, getLocalBounds(),
        juce::Justification::centredBottom, true);

    g.setColour(juce::Colour(0xffffffff));
    g.fillEllipse(15.0f, 7.0f, 22.0f, 22.0f);
    g.setColour(juce::Colour(0xffffc800));
    g.fillEllipse(10.0f, 21.0f, 10.0f, 10.0f);

    g.setColour(juce::Colour(0xff171717));
    g.drawEllipse(10.0f, 21.0f, 10.0f, 10.0f, 2.0f);

    
}

void DarkGUIAudioProcessorEditor::resized()
{
    int size = 80;
    int leftMargin = 750;
    int rightMargin = 130;
    int topDial = 250;
    int bottomDial = 120;

    topBar.setBounds(getWidth() - 800, getHeight() - 290, getWidth(), 30);
    dial1.setBounds(getWidth() - leftMargin, getHeight() - topDial, size, size);
    dial2.setBounds(getWidth() - leftMargin, getHeight() - bottomDial, size, size);
    dial3.setBounds(getWidth() - rightMargin, getHeight() - topDial, size, size);
    dial4.setBounds(getWidth() - rightMargin, getHeight() - bottomDial, size, size);
    moreButton.setBounds(getWidth() - 45, getHeight() - 295, 32, 32);
}