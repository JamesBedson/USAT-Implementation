/*
  ==============================================================================

    LayoutSelectorPanel.cpp
    Created: 12 Jan 2025 11:56:56am
    Author:  James Bedson

  ==============================================================================
*/

#include <JuceHeader.h>
#include "LayoutSelectorPanel.h"

//==============================================================================
LayoutSelectorPanel::LayoutSelectorPanel(StateManager& s,
                                         const UI::FormatType formatType)
: formatType(formatType),
stateManager(s)
{
    addAndMakeVisible(editLayout);
    addAndMakeVisible(saveConfig);
    addAndMakeVisible(loadConfig);
    
    editLayout.setButtonText("edit");
    saveConfig.setButtonText("save");
    loadConfig.setButtonText("load");
    
    editLayout.addListener(this);
    saveConfig.addListener(this);
    loadConfig.addListener(this);
}

LayoutSelectorPanel::~LayoutSelectorPanel()
{
    delete layoutWindow;
}

void LayoutSelectorPanel::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (14.0f));
    g.drawText ("LayoutSelectorPanel", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void LayoutSelectorPanel::resized()
{
    const float
    panelWidth      = getWidth(),
    panelHeight     = getHeight(),
    padding         = (panelWidth + panelHeight) * UI::SpeakerLayoutPanelFactors::paddingFactor,
    buttonWidth     = panelWidth / 3.f - 3 * padding,
    buttonHeight    = panelHeight / 3.f - 2 * padding;
    
    const float
    editX   = padding,
    editY   = getLocalBounds().getBottom() - buttonHeight;
    
    editLayout.setBounds(editX,
                         editY,
                         buttonWidth,
                         buttonHeight
                         );
    
    const float
    saveX = getLocalBounds().getCentreX() - buttonWidth / 2.f,
    saveY = editLayout.getY();
    
    saveConfig.setBounds(saveX,
                         saveY,
                         buttonWidth,
                         buttonHeight
                         );
    
    const float
    loadX = getLocalBounds().getRight() - buttonWidth - padding,
    loadY = editLayout.getY();
    
    loadConfig.setBounds(loadX,
                         loadY,
                         buttonWidth,
                         buttonHeight
                         );
}

void LayoutSelectorPanel::buttonClicked(juce::Button* button)
{
    if (button == &editLayout) {
        
        if (layoutWindow) {
            layoutWindow->broughtToFront();
        }
        else {
            SpeakerLayoutWindow* layoutWindow;
            
            if (formatType == UI::FormatType::input)
                layoutWindow = new SpeakerLayoutWindow("Input Speaker Layout",
                                                       stateManager,
                                                       formatType
                                                       );
            
            else if (formatType == UI::FormatType::output)
                layoutWindow = new SpeakerLayoutWindow("Output Speaker Layout",
                                                       stateManager,
                                                       formatType
                                                       );

            else
                jassertfalse;
        
            layoutWindow->centreWithSize(600, 400);
            layoutWindow->setVisible(true);
        }
    }
    
    else if (button == &saveConfig) {
        DBG("save");
    }
    
    else if (button == &loadConfig) {
        DBG("load");
    }
    
    else
        jassertfalse;
}
