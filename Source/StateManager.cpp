/*
  ==============================================================================

    StateManager.cpp
    Created: 1 Dec 2024 4:38:44pm
    Author:  James Bedson

  ==============================================================================
*/

#include "StateManager.h"

const juce::File StateManager::baseDirectory
{
        juce::File::getSpecialLocation(juce::File::SpecialLocationType::userDocumentsDirectory).getChildFile(ProjectInfo::companyName)
            .getChildFile(ProjectInfo::projectName)
};

const juce::File StateManager::pythonExecutableDirectory
{
        baseDirectory
                .getChildFile(ProcessingConstants::Paths::executableName)
};

const juce::File StateManager::speakerLayoutDirectory
{
    baseDirectory.getChildFile(ProcessingConstants::Paths::speakerLayoutDir)
};

StateManager::StateManager(APVTS& apvts)
: apvts(apvts),
pluginParameterHandler(apvts)
{
    ensureDirectoryExists(baseDirectory);
    ensureDirectoryExists(speakerLayoutDirectory);
    
    DBG("Base Directory Path: " + baseDirectory.getFullPathName());
    DBG("Speaker Layout Path: " + speakerLayoutDirectory.getFullPathName());
}

StateManager::~StateManager()
{
    
}
