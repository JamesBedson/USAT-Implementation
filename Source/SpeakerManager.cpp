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
: speakerTree("Speaker_Layout")
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
    juce::ValueTree speakerInfo {"Speaker_" + juce::String(speakerID)};
    
    jassert(speakerInfo.isValid());
    
    speakerInfo.setProperty(ProcessingConstants::SpeakerProperties::ID,
                            speakerID,
                            nullptr);
    
    speakerInfo.setProperty(ProcessingConstants::SpeakerProperties::azimuth,
                            speakerMap[speakerID]->getCoordinate(Speaker::SphericalCoordinates::Azimuth),
                            nullptr);

    speakerInfo.setProperty(ProcessingConstants::SpeakerProperties::elevation,
                            speakerMap[speakerID]->getCoordinate(Speaker::SphericalCoordinates::Elevation),
                            nullptr);
    
    speakerInfo.setProperty(ProcessingConstants::SpeakerProperties::distance,
                            speakerMap[speakerID]->getCoordinate(Speaker::SphericalCoordinates::Distance),
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
    // Internal List: Find and erase the speaker by ID
    auto it = speakerMap.find(speakerID);
    if (it == speakerMap.end()) {
        jassertfalse;
        return;
    }

    speakerMap.erase(it);
    std::map<int, std::unique_ptr<Speaker>> updatedSpeakerMap;
    
    int newID = 1;
    for (auto& pair : speakerMap) {
        updatedSpeakerMap[newID] = std::move(pair.second);
        ++newID;
    }
    
    speakerMap = std::move(updatedSpeakerMap);
    //printSpeakerMapProperties();

    for (int i = speakerTree.getNumChildren() - 1; i >= 0; --i)
    {
        auto child = speakerTree.getChild(i);
        int childID = child.getProperty(ProcessingConstants::SpeakerProperties::ID);

        if (childID == speakerID)
            speakerTree.removeChild(i,
                                    nullptr);
        
        else if (childID > speakerID)
            child.setProperty(ProcessingConstants::SpeakerProperties::ID,
                              childID - 1,
                              nullptr);
    }
    
    //printSpeakerTreeProperties();
}

void SpeakerManager::saveCurrentLayoutToXML(const juce::File &xmlFile) {
    
    if (auto xml = speakerTree.createXml()) {
        if (!xmlFile.existsAsFile()) {
            auto fileRes = xmlFile.create();
            
            if (fileRes.failed()) {
                DBG("Failed to create XML file for speaker layout: " + fileRes.getErrorMessage());
                jassertfalse;
                return;
            }
        }
        
        if (!xml->writeTo(xmlFile)) {
            DBG("Failed to write to XML file");
            jassertfalse;
        }
        
        else {
            DBG("Successfully saved speaker layout.");
        }
    }
    
    else {
        DBG("Failed to convert value tree to XML");
        jassertfalse;
    }
}


const std::vector<int> SpeakerManager::getVectorCurrentIDs() const
{
    std::vector<int> speakerIDs;
    speakerIDs.reserve(speakerMap.size());

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
    juce::Identifier treeID {"Speaker_" + juce::String(speakerID)};
    auto speakerInfo        = speakerTree.getChildWithName(treeID);
    jassert(speakerInfo.isValid());
    
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

unsigned const int SpeakerManager::getSpeakerCount() const
{
    return static_cast<unsigned int>(speakerMap.size());
}
