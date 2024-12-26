/*
  ==============================================================================

    ParameterParser.h
    Created: 1 Dec 2024 6:09:44pm
    Author:  James Bedson

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "ProcessingConstants.h"
#include "StateManager.h"

using APVTS = juce::AudioProcessorValueTreeState;

class ParameterParser {
    
public:
    ParameterParser(APVTS& apvts, juce::ValueTree& speakerTree);
    ~ParameterParser();
    
    const std::string extractStaticParameters() const;
    const std::string extractSpeakerLayout() const;
    
private:
    void parseEncodingOptions(std::ostringstream& parameterData,
                              const juce::String& encodingOption) const;
    
    template <typename T>
    void formatStaticParameterOption(std::ostringstream& parameterData,
                                   const juce::String& parameterName,
                                   const T& value) const;
    
    void formatSpeakerLayoutOption(std::ostringstream& parameterData,
                                   const int& id,
                                   const float& azimuth,
                                   const float& elevation,
                                   const float& distance) const;
    
    
    ProcessingConstants::PythonParameterNameMap pythonParameterMap;
    
    APVTS&          apvts;
    juce::ValueTree speakerTree;
};
