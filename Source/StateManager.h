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

using APVTS = juce::AudioProcessorValueTreeState;

class StateManager {

public:
    StateManager(SpeakerManager& speakerManager, APVTS& apvts);
    ~StateManager();
    static const juce::File defaultExecutableDirectory;
    static const juce::File executable;
    
    void setUpExecutableDirectory();
    void generateSpeakerValueTree();
    
    APVTS&          staticParameters;
    SpeakerManager& speakerManager;
    juce::ValueTree speakerTree;
    
private:
    
};
