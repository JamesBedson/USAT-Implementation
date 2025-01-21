/*
  ==============================================================================

    DecoderSettingsPanel.cpp
    Created: 11 Jan 2025 1:51:44pm
    Author:  James Bedson

  ==============================================================================
*/

#include <JuceHeader.h>
#include "DecoderSettingsPanel.h"

//==============================================================================
DecoderSettingsPanel::DecoderSettingsPanel(USATAudioProcessor& p)
: audioProcessor(p)
{
    addAndMakeVisible(decode);
    decode.setButtonText("decode");
}

DecoderSettingsPanel::~DecoderSettingsPanel()
{
}

void DecoderSettingsPanel::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (14.0f));
}

void DecoderSettingsPanel::resized()
{
    const float
    buttonCentreX = getLocalBounds().getCentreX(),
    buttonCentreY = getLocalBounds().getCentreY(),
    buttonWidth   = getWidth() * 0.2f,
    buttonHeight  = getHeight() * 0.4f;
    
    decode.setBounds(0, 0, buttonWidth, buttonHeight);
    decode.setCentrePosition(buttonCentreX, buttonCentreY);
    
}
