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
    static const juce::File baseDirectory;
    static const juce::File pythonExecutableDirectory;
    static const juce::File speakerLayoutDirectory;
    
    void ensureDirectoryExists(const juce::File& directory)
    {
        if (!directory.exists())
        {
            auto result = directory.createDirectory();
            if (result.failed())
            {
                DBG("Could not create directory: " + result.getErrorMessage());
                jassertfalse;
            }
        }
    }
    
    APVTS&                      apvts;
    PluginParameterHandler      pluginParameterHandler;
    TranscodingConfigHandler    transcodingConfigHandler;
    
private:
    
};
