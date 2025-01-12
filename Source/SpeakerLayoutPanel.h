/*
  ==============================================================================

    SpeakerLayoutPanel.h
    Created: 12 Jan 2025 2:21:51pm
    Author:  James Bedson

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "StateManager.h"
#include "UIConstants.h"
//==============================================================================
/*
*/
class SpeakerLayoutPanel  : public juce::Component,
public juce::TableListBoxModel, public juce::Button::Listener
{
public:
    
    SpeakerLayoutPanel(StateManager&, const UI::FormatType);
    ~SpeakerLayoutPanel() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    int getNumRows() override;
    
    void paintRowBackground (juce::Graphics&,
                             int rowNumber,
                             int width,
                             int height,
                             bool rowIsSelected) override;
    
    void paintCell (juce::Graphics&,
                    int rowNumber,
                    int columnId,
                    int width,
                    int height,
                    bool rowIsSelected) override;
    
    void buttonClicked (juce::Button*) override;

private:
    
    void initTable();
    const juce::String getText(const int columnNumber,
                               const int rowNumber,
                               const Speaker::SphericalCoordinates);
    juce::TableListBox table;
    
    const UI::FormatType formatType;
    
    juce::TextButton
    addSpeaker,
    removeSpeaker;
    
    StateManager& stateManager;
    SpeakerManager* speakerManager;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpeakerLayoutPanel)
};
