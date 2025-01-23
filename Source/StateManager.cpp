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

const juce::ValueTree StateManager::createGlobalValueTree() const
{
    auto apvtsTree              = apvts.state;
    auto speakerLayoutInTree    = transcodingConfigHandler.speakerManagerInput.getSpeakerTree();
    auto speakerLayoutOutTree   = transcodingConfigHandler.speakerManagerOutput.getSpeakerTree();
    auto coefficientsTree       = pluginParameterHandler.getCoefficientTree();
    
    juce::ValueTree globalTree {ProcessingConstants::TreeTags::globalTreeType};
    
    globalTree.addChild(apvtsTree, 0, nullptr);
    globalTree.addChild(speakerLayoutInTree, 1, nullptr);
    globalTree.addChild(speakerLayoutOutTree, 2, nullptr);
    globalTree.addChild(coefficientsTree, 3, nullptr);
    
    return globalTree;
}
