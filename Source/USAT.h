/*
  ==============================================================================

    USAT.h
    Created: 8 Nov 2024 9:32:14pm
    Author:  James Bedson

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "ProcessingConstants.h"
#include "StateManager.h"

using APVTS = juce::AudioProcessorValueTreeState;

class USAT {
    
public:
    
    USAT();
    ~USAT();
    
    enum MatrixDim{
        Row,
        Column
    };
    
    // Matrix Pre-Processing
    void setChannelCountIn(const int& channelCountIn);
    void setChannelCountOut(const int& channelCountOut);
    void setChannelCounts(const int& channelCountIn, const int& channelCountOut);
    const int getMatrixDimension(const MatrixDim& dimension) const;
    const bool channelAndMatrixDimensionsMatch();
    
    // Matrix Processing
    void computeMatrix(const juce::String parsedValueTree) const;
    const bool decodingMatrixReady();
    void process(juce::AudioBuffer<float>& buffer);
    
private:
    void setParams();
    void reshapeMatrix();
    
    const int getMatrixChannelCountIn();
    const int getMatrixChannelCountOut();
    
    int currentChannelCountIn;
    int currentChannelCountOut;
    
    ProcessingConstants::PythonParameterNameMap pythonParameterMap;
    
    bool matrixReady;
    std::vector<std::vector<float>> gainsMatrix;
};
