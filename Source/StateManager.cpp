/*
  ==============================================================================

    StateManager.cpp
    Created: 1 Dec 2024 4:38:44pm
    Author:  James Bedson

  ==============================================================================
*/

#include "StateManager.h"

const juce::File StateManager::defaultPythonExecutableDirectory
{
        juce::File::getSpecialLocation(juce::File::SpecialLocationType::userDocumentsDirectory).getChildFile(ProjectInfo::companyName)
            .getChildFile(ProjectInfo::projectName)
};

const juce::File StateManager::pythonExecutable
{
        defaultPythonExecutableDirectory
                .getChildFile(ProcessingConstants::Paths::executableName)
};

StateManager::StateManager(APVTS& apvts)
: apvts(apvts),
pluginParameterHandler(apvts)
{
    if (!defaultPythonExecutableDirectory.exists()) {
        // Create directory
        auto result = defaultPythonExecutableDirectory.createDirectory();
        
        if (result.failed()) {
            DBG("Could not create directory: " + result.getErrorMessage());
            jassertfalse;
        }
    }
}

StateManager::~StateManager()
{
    
}
