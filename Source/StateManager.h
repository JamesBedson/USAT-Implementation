/*
  ==============================================================================

    StateManager.h
    Created: 1 Dec 2024 4:38:44pm
    Author:  James Bedson

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "ProcessingConstants.h"
#include "SpeakerManager.h"
#include "TranscodingConfigHandler.h"
#include "PluginParameterHandler.h"

using APVTS = juce::AudioProcessorValueTreeState;

class StateManager {

public:
    StateManager(APVTS& apvts);
    ~StateManager();
    static const juce::File defaultPythonExecutableDirectory;
    static const juce::File pythonExecutable;
    
    void setUpExecutableDirectory();
    
    APVTS&                      apvts;
    PluginParameterHandler      pluginParameterHandler;
    TranscodingConfigHandler    transcodingConfigHandler;
    
private:
    
};
