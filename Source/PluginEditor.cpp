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

    backgroundImage = juce::ImageCache::getFromMemory(BinaryData::background_png, BinaryData::background_pngSize);

    dial1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    dial1.setRange(0.0f, 100.0f);
    dial1.setValue(10.0f);
    dial1.setTextBoxStyle(juce::Slider::NoTextBox, true, 100, 25);
    addAndMakeVisible(dial1);

    dial2.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    dial2.setRange(0.0f, 100.0f);
    dial2.setValue(25.0f);
    dial2.setTextBoxStyle(juce::Slider::NoTextBox, true, 100, 25);
    addAndMakeVisible(dial2);

    dial3.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    dial3.setRange(0.0f, 100.0f);
    dial3.setValue(50.0f);
    dial3.setTextBoxStyle(juce::Slider::NoTextBox, true, 100, 25);
    addAndMakeVisible(dial3);

    dial4.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    dial4.setRange(0.0f, 100.0f);
    dial4.setValue(80.0f);
    dial4.setTextBoxStyle(juce::Slider::NoTextBox, true, 100, 25);
    addAndMakeVisible(dial4);
    addAndMakeVisible(topBar);
    setSize (800, 300);


}

DarkGUIAudioProcessorEditor::~DarkGUIAudioProcessorEditor()
{
    juce::LookAndFeel::setDefaultLookAndFeel(nullptr);
}

//==============================================================================
void DarkGUIAudioProcessorEditor::paint (juce::Graphics& g)
{
    // g.fillAll (juce::Colour(0xff181818));
    g.drawImage(backgroundImage, getLocalBounds().toFloat());

    time_t now = time(0);
    char* dt = ctime(&now);

    g.setColour(juce::Colour(0xff444444));
    g.setFont(12);
    g.drawText("Build 131021-01", getLocalBounds(),
        juce::Justification::centredBottom, true);
    
}

void DarkGUIAudioProcessorEditor::resized()
{
    int size = 80;
    topBar.setBounds(getWidth() - 800, getHeight() - 300, getWidth(), 30);
    dial1.setBounds(getWidth() - 750, getHeight() - 250, size, size);
    dial2.setBounds(getWidth() -750, getHeight() - 120, size, size);
    dial3.setBounds(getWidth() - 130, getHeight() - 250, size, size);
    dial4.setBounds(getWidth() - 130, getHeight() - 120, size, size);
}
