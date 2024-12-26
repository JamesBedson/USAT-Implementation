/*
  ==============================================================================

    SpeakerManager.h
    Created: 1 Dec 2024 7:53:13pm
    Author:  James Bedson

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class Speaker {

public:
    
    enum SphericalCoordinates{
        Azimuth = 0,
        Elevation = 1,
        Distance = 2
    };
    
    Speaker(const float& azimuth,
            const float& elevation,
            const float& distance = 1.f);
    
    ~Speaker();
    
    void changeSpeakerCoordinates(const SphericalCoordinates& coordinate, const float& value);
    const float getCoordinate(const SphericalCoordinates& coordinate) const;
    
private:
    
    bool isValidCoordinate(const SphericalCoordinates& coordinate, const float& value);
    
    std::array<float, 3>
        coordinates;
};

class SpeakerManager {
    
public:
    SpeakerManager();
    ~SpeakerManager();
    
    void addSpeaker(std::unique_ptr<Speaker> newSpeaker, int speakerID);
    void replaceSpeaker(std::unique_ptr<Speaker> newSpeaker, int speakerID);
    void removeSpeaker(int speakerID);
    const std::vector<int> getVectorCurrentIDs() const;
    const Speaker* getSpeaker(int speakerID) const;
    
private:
    
    std::unordered_map<int, std::unique_ptr<Speaker>> speakerMap;
    unsigned int speakerCount;
    
};
