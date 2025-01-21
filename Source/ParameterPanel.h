/*
  ==============================================================================

    ParameterPanel.h
    Created: 11 Jan 2025 2:14:13pm
    Author:  James Bedson

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "StateManager.h"

//==============================================================================
/*
*/
using Attachment = juce::AudioProcessorValueTreeState::SliderAttachment;

class ParameterPanel  : public juce::Component
{
public:
    ParameterPanel(StateManager&);
    ~ParameterPanel() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    StateManager& stateManager;
    
    juce::Slider
    energy,
    radialIntensity,
    pressure,
    radialVelocity,
    transverseVelocity,
    inPhaseQuadratic,
    symmetryQuadratic,
    inPhaseLinear,
    symmetryLinear,
    totalGainsLinear,
    totalGainsQuadratic;
    
    juce::Label
    energyLabel,
    radialIntensityLabel,
    pressureLabel,
    radialVelocityLabel,
    transverseVelocityLabel,
    inPhaseQuadraticLabel,
    symmetryQuadraticLabel,
    inPhaseLinearLabel,
    symmetryLinearLabel,
    totalGainsLinearLabel,
    totalGainsQuadraticLabel;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> energyAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> radialIntensityAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> pressureAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> radialVelocityAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> transverseVelocityAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> inPhaseQuadraticAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> symmetryQuadraticAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> inPhaseLinearAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> symmetryLinearAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> totalGainsLinearAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> totalGainsQuadraticAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParameterPanel)
};

