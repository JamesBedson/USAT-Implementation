/*
  ==============================================================================

    FormatSelectorPanel.cpp
    Created: 11 Jan 2025 2:13:58pm
    Author:  James Bedson

  ==============================================================================
*/

#include <JuceHeader.h>
#include "FormatSelectorPanel.h"

//==============================================================================
FormatSelectorPanel::FormatSelectorPanel(StateManager& s,
                                         const UI::FormatType formatType)
: stateManager(s),
layoutSelectorPanel(s, formatType),
ambisonicsSelectorPanel(s, formatType)
{
    addAndMakeVisible(comboBox);
    addChildComponent(layoutSelectorPanel);
    addChildComponent(ambisonicsSelectorPanel);
    
    comboBox.addListener(this);
    comboBox.addItem("Speaker Layout", 1);
    comboBox.addItem("Ambisonics", 2);
}

FormatSelectorPanel::~FormatSelectorPanel()
{
}

void FormatSelectorPanel::paint (juce::Graphics& g)
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
    g.drawText ("FormatSelectorPanel", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void FormatSelectorPanel::resized()
{
    const float
    panelWidth      = getWidth(),
    panelHeight     = getHeight(),
    padding         = (panelWidth + panelHeight) * UI::FormatSelectionFactors::paddingFactor,
    comboBoxWidth   = panelWidth - 2.f * padding,
    comboBoxHeight  = panelHeight * UI::FormatSelectionFactors::comboBoxHeightFactor;
    
    comboBox.setBounds(padding,
                       padding,
                       comboBoxWidth,
                       comboBoxHeight
                       );
    
    const float
    selectorPanelX = padding,
    selectorPanelY = comboBox.getBottom() + padding,
    selectorPanelWidth = comboBoxWidth,
    selectorPanelHeight = panelHeight - comboBoxHeight - 3.f * padding;
    
    layoutSelectorPanel.setBounds(selectorPanelX,
                                  selectorPanelY,
                                  selectorPanelWidth, selectorPanelHeight
                                  );
    
    ambisonicsSelectorPanel.setBounds(selectorPanelX,
                                      selectorPanelY,
                                      selectorPanelWidth,
                                      selectorPanelHeight
                                      );
}

void FormatSelectorPanel::comboBoxChanged(juce::ComboBox *comboBoxThatHasChanged)
{
    if (comboBoxThatHasChanged == &comboBox) {
        
        const int selectedID = comboBox.getSelectedId();
        
        switch (selectedID) {
            case 1:
                ambisonicsSelectorPanel.setVisible(false);
                layoutSelectorPanel.setVisible(true);
                break;
                
            case 2:
                layoutSelectorPanel.setVisible(false);
                ambisonicsSelectorPanel.setVisible(true);
                break;
        }
        
    }
}
