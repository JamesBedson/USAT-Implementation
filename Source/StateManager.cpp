/*
  ==============================================================================

    StateManager.cpp
    Created: 1 Dec 2024 4:38:44pm
    Author:  James Bedson

  ==============================================================================
*/

#include "StateManager.h"

const juce::File StateManager::defaultExecutableDirectory {
    juce::File::getSpecialLocation(juce::File::SpecialLocationType::userDocumentsDirectory).getChildFile(ProjectInfo::companyName).getChildFile(ProjectInfo::projectName)
};

const juce::File StateManager::executable {
    defaultExecutableDirectory.getChildFile(ProcessingConstants::Paths::executableName)
};

StateManager::StateManager(SpeakerManager& speakerManager, APVTS& staticParameters)
: staticParameters(staticParameters),
speakerManager(speakerManager)
{
    if (!defaultExecutableDirectory.exists()) {
        // Create directory
        auto result = defaultExecutableDirectory.createDirectory();
        
        if (result.failed()) {
            DBG("Could not create directory: " + result.getErrorMessage());
            jassertfalse;
        }
    }
}

StateManager::~StateManager()
{
    
}

void StateManager::generateSpeakerValueTree()
{
    speakerTree.removeAllChildren(nullptr);
    auto speakerIDs = speakerManager.getVectorCurrentIDs();
    
    for (auto id : speakerIDs) {
        
        juce::ValueTree speaker("Speaker");
        speaker.setProperty(ProcessingConstants::SpeakerProperties::ID, id, nullptr);
        
        auto currentSpeaker = speakerManager.getSpeaker(id);
        
        speaker.setProperty(
                            ProcessingConstants::SpeakerProperties::azimuth,
                            currentSpeaker->getCoordinate(Speaker::SphericalCoordinates::Azimuth), nullptr
                            );
        
        speaker.setProperty(
                            ProcessingConstants::SpeakerProperties::elevation,
                            currentSpeaker->getCoordinate(Speaker::SphericalCoordinates::Elevation), nullptr
                            );
        
        speaker.setProperty(
                            ProcessingConstants::SpeakerProperties::distance,
                            currentSpeaker->getCoordinate(Speaker::SphericalCoordinates::Distance), nullptr
                            );
        
        speakerTree.appendChild(speaker, nullptr);
    }
    
}
