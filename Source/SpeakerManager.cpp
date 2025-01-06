/*
  ==============================================================================

    SpeakerManager.cpp
    Created: 1 Dec 2024 7:53:13pm
    Author:  James Bedson

  ==============================================================================
*/

#include "SpeakerManager.h"
// ================================================================================================================
Speaker::Speaker(const float& azimuth,
                 const float& elevation,
                 const float& distance)
{
    coordinates[SphericalCoordinates::Azimuth]      = azimuth;
    coordinates[SphericalCoordinates::Elevation]    = elevation;
    coordinates[SphericalCoordinates::Distance]     = distance;
}

Speaker::~Speaker()
{
    
}

void Speaker::changeSpeakerCoordinates(const SphericalCoordinates &coordinate, const float &value)
{
    if (isValidCoordinate(coordinate, value))
        coordinates[coordinate] = value;
    else
        jassertfalse;
}


bool Speaker::isValidCoordinate(const SphericalCoordinates &coordinate, const float &value)
{
    
    switch (coordinate) {
        case Azimuth:
            return value >= 0 && value <= 360;
            
        case Elevation:
            return value >= 0 && value <= 90;
            
        case Distance:
            return true;
    }
}

const float Speaker::getCoordinate(const SphericalCoordinates& coordinate) const
{
    return coordinates[coordinate];
}

// ==================================================================================================================

SpeakerManager::SpeakerManager()
{
    
}

SpeakerManager::~SpeakerManager()
{
    
}

void SpeakerManager::addSpeaker(std::unique_ptr<Speaker> newSpeaker, int speakerID)
{
    
    // Internal List
    if (speakerMap.find(speakerID) != speakerMap.end())
        jassertfalse;
    
    speakerMap[speakerID] = std::move(newSpeaker);
    
    // Speaker Tree
    juce::ValueTree speakerInfo;
    speakerInfo.setProperty(ProcessingConstants::SpeakerProperties::azimuth,
                            newSpeaker->getCoordinate(Speaker::SphericalCoordinates::Azimuth),
                            nullptr);

    speakerInfo.setProperty(ProcessingConstants::SpeakerProperties::elevation,
                            newSpeaker->getCoordinate(Speaker::SphericalCoordinates::Elevation),
                            nullptr);
    
    speakerInfo.setProperty(ProcessingConstants::SpeakerProperties::distance,
                            newSpeaker->getCoordinate(Speaker::SphericalCoordinates::Distance),
                            nullptr);
    
    speakerTree.appendChild(speakerInfo, nullptr);
}

void SpeakerManager::replaceSpeaker(std::unique_ptr<Speaker> newSpeaker, int speakerID)
{
    auto it = speakerMap.find(speakerID);
    if (it == speakerMap.end())
        jassertfalse;

    it->second = std::move(newSpeaker);
}

void SpeakerManager::removeSpeaker(int speakerID)
{
    // Internal List
    auto it = speakerMap.find(speakerID);
    if (it == speakerMap.end())
        jassertfalse;
    speakerMap.erase(it);
    
    // Speaker Tree
    auto speakerInfo = speakerTree.getChildWithProperty(ProcessingConstants::SpeakerProperties::ID,
                                                        speakerID);
    if (speakerInfo.isValid())
        speakerTree.removeChild(speakerInfo, nullptr);
}

const std::vector<int> SpeakerManager::getVectorCurrentIDs() const
{
    std::vector<int> speakerIDs;
    speakerIDs.reserve(speakerMap.size()); // Reserve space to avoid reallocations

    for (const auto& pair : speakerMap) {
        speakerIDs.push_back(pair.first);
    }

    return speakerIDs;
}

const Speaker* SpeakerManager::getSpeaker(int speakerID) const
{
    auto it = speakerMap.find(speakerID);
    
    if (it != speakerMap.end()) {
        return it->second.get();
    }
    
    else {
        jassertfalse;
        return nullptr;
    }
}

void SpeakerManager::generateSpeakerTree()
{
    speakerTree.removeAllChildren(nullptr);
    auto speakerIDs = getVectorCurrentIDs();
    
    for (auto id : speakerIDs) {
        
        juce::ValueTree speakerInfo(static_cast<juce::String>(std::to_string(id)));
        speakerInfo.setProperty(ProcessingConstants::SpeakerProperties::ID, id, nullptr);
        
        auto currentSpeaker = getSpeaker(id);
        
        speakerInfo.setProperty(
                            ProcessingConstants::SpeakerProperties::azimuth,
                            currentSpeaker->getCoordinate(Speaker::SphericalCoordinates::Azimuth), nullptr
                            );
        
        speakerInfo.setProperty(
                            ProcessingConstants::SpeakerProperties::elevation,
                            currentSpeaker->getCoordinate(Speaker::SphericalCoordinates::Elevation), nullptr
                            );
        
        speakerInfo.setProperty(
                            ProcessingConstants::SpeakerProperties::distance,
                            currentSpeaker->getCoordinate(Speaker::SphericalCoordinates::Distance), nullptr
                            );
        
        speakerTree.appendChild(speakerInfo, nullptr);
    }
}

void SpeakerManager::modifySpeakerProperty(int speakerID,
                                           Speaker::SphericalCoordinates coordinate,
                                           const float value)
{
    jassert(Speaker::isValidCoordinate(coordinate, value));
    
    // Modify Speaker in Map
    auto it             = speakerMap.find(speakerID);
    Speaker* speaker    = it->second.get();
    jassert(speaker != nullptr);
    speaker->changeSpeakerCoordinates(coordinate, value);
    
    // Modify Speaker in Speaker Tree
    juce::Identifier treeID = static_cast<juce::String>(std::to_string(speakerID));
    auto speakerInfo        = speakerTree.getChildWithName(treeID);
    
    switch (coordinate) {
        case Speaker::Azimuth:
            speakerInfo.setProperty(ProcessingConstants::SpeakerProperties::azimuth,
                                    value,
                                    nullptr);
            break;
            
        case Speaker::Elevation:
            speakerInfo.setProperty(ProcessingConstants::SpeakerProperties::elevation,
                                    value,
                                    nullptr);
            break;
            
        case Speaker::Distance:
            speakerInfo.setProperty(ProcessingConstants::SpeakerProperties::distance,
                                    value,
                                    nullptr);
    }
}

juce::ValueTree& SpeakerManager::getSpeakerTree() {
    return speakerTree;
}
