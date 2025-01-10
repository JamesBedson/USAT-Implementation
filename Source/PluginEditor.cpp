/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "UIConstants.h"

// WRAPPER
//==============================================================================
WrappedAudioProcessorEditor::WrappedAudioProcessorEditor (USATAudioProcessor& p)
    : juce::AudioProcessorEditor(p),
    rasterComponent(p),
    audioProcessor (p)
{
    addAndMakeVisible(rasterComponent);
    if (auto constrainer = getConstrainer())
    {
        constrainer->setFixedAspectRatio(UI::SizeLimits::maximumWidth / UI::SizeLimits::maximumHeight);
        
        constrainer->setSizeLimits(UI::SizeLimits::minimumWidth,
                                   UI::SizeLimits::minimumHeight,
                                   UI::SizeLimits::maximumWidth,
                                   UI::SizeLimits::maximumHeight
                                   );
    }
    setResizable(true, true);
    setSize (UI::SizeLimits::maximumWidth, UI::SizeLimits::maximumHeight);
}

WrappedAudioProcessorEditor::~WrappedAudioProcessorEditor()
{
    
}

void WrappedAudioProcessorEditor::resized()
{
    const auto scaleFactor = static_cast<float>(getWidth()) / UI::SizeLimits::maximumWidth;
    rasterComponent.setTransform(juce::AffineTransform::scale(scaleFactor));
    
}

// RASTER COMPONENT
//==============================================================================

RasterComponent::RasterComponent(USATAudioProcessor& p)
: audioProcessor(p)
{
    
}

RasterComponent::~RasterComponent()
{
    
}

void RasterComponent::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void RasterComponent::resized()
{
    
}
