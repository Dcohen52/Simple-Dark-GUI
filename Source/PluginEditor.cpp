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

    fatness.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    fatness.setRange(0.0f, 100.0f);
    fatness.setValue(10.0f);
    fatness.setTextBoxStyle(juce::Slider::NoTextBox, true, 100, 25);
    addAndMakeVisible(fatness);

    glitter.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    glitter.setRange(0.0f, 100.0f);
    glitter.setValue(25.0f);
    glitter.setTextBoxStyle(juce::Slider::NoTextBox, true, 100, 25);
    addAndMakeVisible(glitter);

    medbell.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    medbell.setRange(0.0f, 100.0f);
    medbell.setValue(50.0f);
    medbell.setTextBoxStyle(juce::Slider::NoTextBox, true, 100, 25);
    addAndMakeVisible(medbell);

    cutoff.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    cutoff.setRange(0.0f, 100.0f);
    cutoff.setValue(80.0f);
    cutoff.setTextBoxStyle(juce::Slider::NoTextBox, true, 100, 25);
    addAndMakeVisible(cutoff);
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
    fatness.setBounds(getWidth() - 750, getHeight() - 250, size, size);
    glitter.setBounds(getWidth() -750, getHeight() - 120, size, size);
    medbell.setBounds(getWidth() - 130, getHeight() - 250, size, size);
    cutoff.setBounds(getWidth() - 130, getHeight() - 120, size, size);
}
