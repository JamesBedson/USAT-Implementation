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
    if (speakerMap.find(speakerID) != speakerMap.end())
        jassertfalse;
    
    speakerMap[speakerID] = std::move(newSpeaker);
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
    auto it = speakerMap.find(speakerID);
    if (it == speakerMap.end())
        jassertfalse;
    
    speakerMap.erase(it);
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
