/*
  ==============================================================================

    ParameterParser.cpp
    Created: 1 Dec 2024 6:09:44pm
    Author:  James Bedson

  ==============================================================================
*/

#include "ParameterParser.h"

ParameterParser::ParameterParser(APVTS& apvts, juce::ValueTree& speakerTree)
: apvts(apvts),
speakerTree(speakerTree)
{
    
}

ParameterParser::~ParameterParser()
{
    
}

const std::string ParameterParser::extractStaticParameters() const
{
    
    // =============================================================================================================
    
    std::ostringstream
        parameterData;
    
    // Encoding Settings: Inputs and Outputs
    parseEncodingOptions(parameterData, ProcessingConstants::EncodingOptions::inputType);
    parseEncodingOptions(parameterData, ProcessingConstants::EncodingOptions::outputType);
    
    // Coefficients
    for (const auto& [key, parameterName] : pythonParameterMap.coefficientMap)
    {
        float value = apvts.getRawParameterValue(key)->load();
        formatStaticParameterOption(parameterData, parameterName, value);
    }
    
    return parameterData.str();
}

void ParameterParser::parseEncodingOptions(std::ostringstream& parameterData,
                                             const juce::String& encodingOption) const
{
    // ====================================================================================================================================================
    // Top Level Setting: Input or Output ?
    
    int topLevelEncodingOptionIdx           = static_cast<int>(apvts.getRawParameterValue(encodingOption)->load());
    juce::String topLevelEncodingOption     = ProcessingConstants::EncodingOptions::encodingChoices[topLevelEncodingOptionIdx];
    juce::String pythonTopLevelOptionName   = pythonParameterMap.encodingOptionMap.at(encodingOption);
    formatStaticParameterOption(parameterData,
                              pythonTopLevelOptionName,
                              topLevelEncodingOption);
    
    // ====================================================================================================================================================
    // Low Level Setting: Ambisonics or Surround ?
    
    int
        lowLevelEncodingOptionIdx;
    
    juce::String
        lowLevelEncodingOption,
        pythonLowLevelOptionName = pythonParameterMap.encodingOptionMap.at(topLevelEncodingOption);
    
    
    if (topLevelEncodingOption == ProcessingConstants::EncodingOptions::ambisonics) {
        lowLevelEncodingOptionIdx   = static_cast<int>(apvts.getRawParameterValue(ProcessingConstants::EncodingOptions::Ambisonics::order)->load());
        lowLevelEncodingOption      = ProcessingConstants::EncodingOptions::Ambisonics::orderChoices[lowLevelEncodingOptionIdx];
    }
    
    else if (topLevelEncodingOption == ProcessingConstants::EncodingOptions::surround) {
        lowLevelEncodingOptionIdx   = static_cast<int>(apvts.getRawParameterValue(ProcessingConstants::EncodingOptions::Surround::surroundLayout)->load());
        lowLevelEncodingOption      = ProcessingConstants::EncodingOptions::Surround::layoutChoices[lowLevelEncodingOptionIdx];
    }
    
    else
        jassertfalse;
    
    formatStaticParameterOption(parameterData,
                              pythonLowLevelOptionName,
                              lowLevelEncodingOption);
    
    // ====================================================================================================================================================
}

template <typename T>
void ParameterParser::formatStaticParameterOption(std::ostringstream& parameterData,
                                     const juce::String& parameterName,
                                     const T& value) const
{
    parameterData   << parameterName
                    << "="
                    << value
                    << ";";
}

const std::string ParameterParser::extractSpeakerLayout() const {
    std::ostringstream
        speakerData;
    
    for (int i = 0; i < speakerTree.getNumChildren(); i++) {
        auto currentSpeaker = speakerTree.getChild(i);
        auto speakerID      = currentSpeaker.getProperty(ProcessingConstants::SpeakerProperties::ID);
        auto azimuth        = currentSpeaker.getProperty(ProcessingConstants::SpeakerProperties::azimuth);
        auto elevation      = currentSpeaker.getProperty(ProcessingConstants::SpeakerProperties::elevation);
        auto distance       = currentSpeaker.getProperty(ProcessingConstants::SpeakerProperties::distance);
        
        formatSpeakerLayoutOption(speakerData, speakerID, azimuth, elevation, distance);
    }
    return speakerData.str();
    
}

void ParameterParser::formatSpeakerLayoutOption(std::ostringstream& speakerData,
                                                const int& id,
                                                const float& azimuth,
                                                const float& elevation,
                                                const float& distance) const
{
    speakerData << id << "="
                << azimuth << ","
                << elevation << ","
                << distance
                << ";";
}
