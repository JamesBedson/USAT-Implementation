/*
  ==============================================================================

    UIConstants.h
    Created: 10 Jan 2025 6:07:36pm
    Author:  James Bedson

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>


namespace UI {

namespace SizeLimits {

static constexpr double
maximumWidth {1200.0},
maximumHeight {800.0};

static constexpr double
minimumWidth    = maximumWidth / 4.0,
minimumHeight   = maximumHeight / 4.0;

}

namespace ComponentFactors {

static constexpr float
margin                      = SizeLimits::maximumWidth * 0.01f,
headerHeightFactor          = 0.2f,
mainBodyFactor              = 0.6,
settingsBodyFactor          = 1 - headerHeightFactor - mainBodyFactor,
parameterPanelFactor        = 0.4,
visualisationPanelFactor    = 1 - parameterPanelFactor;

}

}
