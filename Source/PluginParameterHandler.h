/*
  ==============================================================================

    ParameterHandler.h
    Created: 26 Dec 2024 5:34:53pm
    Author:  James Bedson

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "ProcessingConstants.h"

using APVTS = juce::AudioProcessorValueTreeState;

class PluginParameterHandler {
    
public:
    PluginParameterHandler(APVTS&);
    void initialiseCoefficients();
    void modifyCoefficient(const juce::String& coefficientName,
                           const float& coefficientValue);
    juce::ValueTree& getCoefficientTree();
    
    
private:
    APVTS&          userParameters;
    juce::ValueTree coefficientTree;
    
};
