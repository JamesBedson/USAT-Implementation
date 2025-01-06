/*
  ==============================================================================

    ParameterDefinitions.h
    Created: 20 Nov 2024 8:45:02pm
    Author:  James Bedson

  ==============================================================================
*/

#pragma once

{
    // =========================================================================
    // PLUGIN PARAMETERS (Control the actual UI parameters)
    
    // bypass
    std::make_unique<juce::AudioParameterBool> (juce::ParameterID {ProcessingConstants::PluginParameterNames::bypass, 1},
                                                ProcessingConstants::PluginParameterNames::bypass,
                                                false),
    
    // =========================================================================
    // EncodingOptions
    
    // input type
    std::make_unique<juce::AudioParameterChoice>(juce::ParameterID {ProcessingConstants::EncodingOptions::inputType, 1},
                                                 ProcessingConstants::EncodingOptions::inputType,
                                                 ProcessingConstants::EncodingOptions::encodingChoices,
                                                 0
                                                 ),
    // output type
    std::make_unique<juce::AudioParameterChoice>(juce::ParameterID {ProcessingConstants::EncodingOptions::outputType, 1},
                                                 ProcessingConstants::EncodingOptions::outputType,
                                                 ProcessingConstants::EncodingOptions::encodingChoices,
                                                 1
                                                 ),
    // ambisonics order
    std::make_unique<juce::AudioParameterChoice>(juce::ParameterID {ProcessingConstants::EncodingOptions::Ambisonics::order, 1},
                                                 ProcessingConstants::EncodingOptions::Ambisonics::order,
                                                 ProcessingConstants::EncodingOptions::Ambisonics::orderChoices,
                                                 0
                                                 ),
    
    // surround layout
    std::make_unique<juce::AudioParameterChoice>(juce::ParameterID {ProcessingConstants::EncodingOptions::Surround::surroundLayout, 1},
                                                 ProcessingConstants::EncodingOptions::Surround::surroundLayout,
                                                 ProcessingConstants::EncodingOptions::Surround::layoutChoices,
                                                 0
                                                 ),
    
    // =========================================================================
    // Coefficients (Control the algorithm parameters)
    
    // energy
    std::make_unique<juce::AudioParameterFloat>(
                                                juce::ParameterID {ProcessingConstants::Coeffs::energy, 1},
                                                ProcessingConstants::Coeffs::energy,
                                                juce::NormalisableRange<float>(
                                                                               ProcessingConstants::Coeffs::startValEnergy,
                                                                               ProcessingConstants::Coeffs::endValEnergy,
                                                                               ProcessingConstants::Coeffs::incrementEnergy,
                                                                               ProcessingConstants::Coeffs::skewEnergy
                                                                               ),
                                                ProcessingConstants::Coeffs::defaultEnergy
    ),

    // radial intensity
    std::make_unique<juce::AudioParameterFloat>(
                                                juce::ParameterID {ProcessingConstants::Coeffs::radialIntensity, 1},
                                                ProcessingConstants::Coeffs::radialIntensity,
                                                juce::NormalisableRange<float>(
                                                                               ProcessingConstants::Coeffs::startValRadialIntensity,
                                                                               ProcessingConstants::Coeffs::endValRadialIntensity,
                                                                               ProcessingConstants::Coeffs::incrementRadialIntensity,
                                                                               ProcessingConstants::Coeffs::skewRadialIntensity
                                                                               ),
                                                ProcessingConstants::Coeffs::defaultRadialIntensity
    ),

    // transverse intensity
    std::make_unique<juce::AudioParameterFloat>(
                                                juce::ParameterID {ProcessingConstants::Coeffs::transverseIntensity, 1},
                                                ProcessingConstants::Coeffs::transverseIntensity,
                                                juce::NormalisableRange<float>(
                                                                               ProcessingConstants::Coeffs::startValTransverseIntensity,
                                                                               ProcessingConstants::Coeffs::endValTransverseIntensity,
                                                                               ProcessingConstants::Coeffs::incrementTransverseIntensity,
                                                                               ProcessingConstants::Coeffs::skewTransverseIntensity
                                                                               ),
                                                ProcessingConstants::Coeffs::defaultTransverseIntensity
                                                ),

    // pressure
    std::make_unique<juce::AudioParameterFloat>(
                                                juce::ParameterID {ProcessingConstants::Coeffs::pressure, 1},
                                                ProcessingConstants::Coeffs::pressure,
                                                juce::NormalisableRange<float>(
                                                                               ProcessingConstants::Coeffs::startValPressure,
                                                                               ProcessingConstants::Coeffs::endValPressure,
                                                                               ProcessingConstants::Coeffs::incrementPressure,
                                                                               ProcessingConstants::Coeffs::skewPressure
                                                                               ),
                                                ProcessingConstants::Coeffs::defaultPressure
    ),

    // radial velocity
    std::make_unique<juce::AudioParameterFloat>(
                                                juce::ParameterID {ProcessingConstants::Coeffs::radialVelocity, 1},
                                                ProcessingConstants::Coeffs::radialVelocity,
                                                juce::NormalisableRange<float>(
                                                                               ProcessingConstants::Coeffs::startValRadialVelocity,
                                                                               ProcessingConstants::Coeffs::endValRadialVelocity,
                                                                               ProcessingConstants::Coeffs::incrementRadialVelocity,
                                                                               ProcessingConstants::Coeffs::skewRadialVelocity
                                                                               ),
                                                ProcessingConstants::Coeffs::defaultRadialVelocity // Typo? Should be defaultRadialVelocity
    ),

    // transverse velocity
    std::make_unique<juce::AudioParameterFloat>(
                                                juce::ParameterID {ProcessingConstants::Coeffs::transverseVelocity, 1},
                                                ProcessingConstants::Coeffs::transverseVelocity,
                                                juce::NormalisableRange<float>(
                                                                               ProcessingConstants::Coeffs::startValTransverseVelocity,
                                                                               ProcessingConstants::Coeffs::endValTransverseVelocity,
                                                                               ProcessingConstants::Coeffs::incrementTransverseVelocity,
                                                                               ProcessingConstants::Coeffs::skewTransverseVelocity
                                                                               ),
                                                ProcessingConstants::Coeffs::defaultTransverseVelocity
    ),

    // in-phase quadratic
    std::make_unique<juce::AudioParameterFloat>(
                                                juce::ParameterID {ProcessingConstants::Coeffs::inPhaseQuadratic, 1},
                                                ProcessingConstants::Coeffs::inPhaseQuadratic,
                                                juce::NormalisableRange<float>(
                                                                               ProcessingConstants::Coeffs::startValInPhaseQuadratic,
                                                                               ProcessingConstants::Coeffs::endValInPhaseQuadratic,
                                                                               ProcessingConstants::Coeffs::incrementInPhaseQuadratic,
                                                                               ProcessingConstants::Coeffs::skewInPhaseQuadratic
                                                                               ),
                                                ProcessingConstants::Coeffs::defaultInPhaseQuadratic
    ),
    
    // symmetry quadratic
    std::make_unique<juce::AudioParameterFloat>(
                                                juce::ParameterID {ProcessingConstants::Coeffs::symmetryQuadratic, 1},
                                                ProcessingConstants::Coeffs::symmetryQuadratic,
                                                juce::NormalisableRange<float>(
                                                                               ProcessingConstants::Coeffs::startValSymmetryQuadratic,
                                                                               ProcessingConstants::Coeffs::endValSymmetryQuadratic,
                                                                               ProcessingConstants::Coeffs::incrementSymmetryQuadratic,
                                                                               ProcessingConstants::Coeffs::skewSymmetryQuadratic
                                                                               ),
                                                ProcessingConstants::Coeffs::defaultSymmetryQuadratic
    ),

    // in-phase linear
    std::make_unique<juce::AudioParameterFloat>(
                                                juce::ParameterID {ProcessingConstants::Coeffs::inPhaseLinear, 1},
                                                ProcessingConstants::Coeffs::inPhaseLinear,
                                                juce::NormalisableRange<float>(
                                                                               ProcessingConstants::Coeffs::startValInPhaseLinear,
                                                                               ProcessingConstants::Coeffs::endValInPhaseLinear,
                                                                               ProcessingConstants::Coeffs::incrementInPhaseLinear,
                                                                               ProcessingConstants::Coeffs::skewInPhaseLinear
                                                                               ),
                                                ProcessingConstants::Coeffs::defaultInPhaseLinear
    ),

    // symmetry linear
    std::make_unique<juce::AudioParameterFloat>(
                                                juce::ParameterID {ProcessingConstants::Coeffs::symmetryLinear, 1},
                                                ProcessingConstants::Coeffs::symmetryLinear,
                                                juce::NormalisableRange<float>(
                                                                               ProcessingConstants::Coeffs::startValSymmetryLinear,
                                                                               ProcessingConstants::Coeffs::endValSymmetryLinear,
                                                                               ProcessingConstants::Coeffs::incrementSymmetryLinear,
                                                                               ProcessingConstants::Coeffs::skewSymmetryLinear
                                                                               ),
                                                ProcessingConstants::Coeffs::defaultSymmetryLinear
    ),

    // total gains linear
    std::make_unique<juce::AudioParameterFloat>(
                                                juce::ParameterID {ProcessingConstants::Coeffs::totalGainsLinear, 1},
                                                ProcessingConstants::Coeffs::totalGainsLinear,
                                                juce::NormalisableRange<float>(
                                                                               ProcessingConstants::Coeffs::startValTotalGainsLinear,
                                                                               ProcessingConstants::Coeffs::endValTotalGainsLinear,
                                                                               ProcessingConstants::Coeffs::incrementTotalGainsLinear,
                                                                               ProcessingConstants::Coeffs::skewTotalGainsLinear
                                                                               ),
                                                ProcessingConstants::Coeffs::defaultTotalGainsLinear
    ),

    // total gains quadratic
    std::make_unique<juce::AudioParameterFloat>(
                                                juce::ParameterID {ProcessingConstants::Coeffs::totalGainsQuadratic, 1},
                                                ProcessingConstants::Coeffs::totalGainsQuadratic,
                                                juce::NormalisableRange<float>(
                                                                               ProcessingConstants::Coeffs::startValTotalGainsQuadratic,
                                                                               ProcessingConstants::Coeffs::endValTotalGainsQuadratic,
                                                                               ProcessingConstants::Coeffs::incrementTotalGainsQuadratic,
                                                                               ProcessingConstants::Coeffs::skewTotalGainsQuadratic
                                                                               ),
                                                ProcessingConstants::Coeffs::defaultTotalGainsQuadratic
    ),

}
