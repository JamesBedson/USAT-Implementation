/*
  ==============================================================================

    USAT.cpp
    Created: 8 Nov 2024 9:32:14pm
    Author:  James Bedson

  ==============================================================================
*/

#include "USAT.h"

USAT::USAT()
{
    
    
}

USAT::~USAT()
{
    
}


// CONFIGURATION ================================================================

const bool USAT::decodingMatrixReady()
{
    return false;
}

const int USAT::getMatrixChannelCountIn()
{
    return static_cast<int>(gainsMatrix.size());
}

const int USAT::getMatrixChannelCountOut()
{
    if (gainsMatrix.size() > 0) {
        int initialOutputDimension = static_cast<int>(gainsMatrix[0].size());
        
        for (int i = 1; i < gainsMatrix.size(); i++) {
            if (gainsMatrix[i].size() != initialOutputDimension)
                return -1;
        }
    
        return initialOutputDimension;
    }
    
    return 0;
}

void USAT::setChannelCountIn(const int& channelCountIn)
{
    currentChannelCountIn = channelCountIn;
    reshapeMatrix();
}

void USAT::setChannelCountOut(const int& channelCountOut)
{
    currentChannelCountOut = channelCountOut;
    reshapeMatrix();
}

void USAT::setChannelCounts(const int &channelCountIn, const int &channelCountOut)
{
    currentChannelCountIn   = channelCountIn;
    currentChannelCountOut  = channelCountOut;
    reshapeMatrix();
}

const int USAT::getMatrixDimension(const MatrixDim& dimension) const {
    if (dimension == MatrixDim::Row) {
        return static_cast<int>(gainsMatrix.size());
    }
    
    else {
        return static_cast<int>(gainsMatrix.at(0).size());
    }
}

const bool USAT::channelAndMatrixDimensionsMatch()
{
    return (getMatrixChannelCountIn() == currentChannelCountIn)
    && (getMatrixChannelCountOut() == currentChannelCountOut);
}

// GAINS ========================================================================

void USAT::computeMatrix(const std::string& parameters) const
{
    // Call python script with parameters
    
    auto executablePath     = StateManager::pythonExecutable.getFullPathName();
    auto quotedParameters   = "\"" + parameters + "\"";
    auto command            = executablePath + " " + quotedParameters;
    
    juce::ChildProcess pythonExecutableUSAT;
    bool success = pythonExecutableUSAT.start(command);
    
    if (success) {
        juce::String output = pythonExecutableUSAT.readAllProcessOutput();
        DBG(output);
        pythonExecutableUSAT.kill();
    }
    
    else {
        DBG("Error launching executable...");
    }
    
}

void USAT::reshapeMatrix()
{
    gainsMatrix.resize(currentChannelCountIn);
    
    for (int chIn = 0; chIn < currentChannelCountIn; chIn++)
        gainsMatrix[chIn].resize(currentChannelCountOut);
}

// ==============================================================
void USAT::process(juce::AudioBuffer<float> &buffer) {
    
}


