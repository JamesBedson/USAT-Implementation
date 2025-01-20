/*
  ==============================================================================

    ProcessingConstants.h
    Created: 20 Nov 2024 8:50:24pm
    Author:  James Bedson

  ==============================================================================
*/

#pragma once
namespace ProcessingConstants {

    namespace Paths {
    const juce::String executableName   = "receive_parameters";
    const juce::String speakerLayoutDir = "Speaker_Layouts";
    
    }

    namespace SpeakerProperties {
    
    const juce::String  ID          = "ID";
    const juce::String  azimuth     = "Azimuth";
    const juce::String  elevation   = "Elevation";
    const juce::String  distance    = "Distance";
    }

    namespace PluginParameterNames {
        
    const juce::String bypass = "bypass";
    
    }

    namespace EncodingOptions {
    
    const juce::String inputType    = "inputType";
    const juce::String outputType   = "outputType";
    
    const juce::String ambisonics   = "ambisonics";
    const juce::String surround     = "surround";
    
    // EncodingOptions
    const juce::StringArray encodingChoices {
        ProcessingConstants::EncodingOptions::ambisonics,
        ProcessingConstants::EncodingOptions::surround
    };
    
        namespace Ambisonics {
            const juce::String order = "ambisonicsOrder";
            const juce::StringArray orderChoices {
                "1", "2", "3", "4", "5", "6", "7"
            };
        }
    
        namespace Surround {
            const juce::String surroundLayout   = "surroundLayout";
            const juce::StringArray layoutChoices {
                "5.1.4",
                "7.1.4",
                "9.1.6"
            };
        }
    }
    
    namespace Coeffs {
    
    // ================================================================
    // Names
    
    const juce::String  energy                  = "energy";
    const juce::String  radialIntensity         = "radialIntensity";
    const juce::String  transverseIntensity     = "transverseIntensity";
    const juce::String  pressure                = "pressure";
    const juce::String  radialVelocity          = "radialVelocity";
    const juce::String  transverseVelocity      = "transverseVelocity";
    const juce::String  inPhaseQuadratic        = "inPhaseQuadratic";
    const juce::String  symmetryQuadratic       = "symmetryQuadratic";
    const juce::String  inPhaseLinear           = "inPhaseLinear";
    const juce::String  symmetryLinear          = "symmetryLinear";
    const juce::String  totalGainsLinear        = "totalGainsLinear";
    const juce::String  totalGainsQuadratic     = "totalGainsQuadratic";
    
    const juce::StringArray coefficientTypes {
        
        energy,
        radialIntensity,
        transverseIntensity,
        pressure,
        radialVelocity,
        transverseVelocity,
        inPhaseQuadratic,
        symmetryQuadratic,
        inPhaseLinear,
        symmetryLinear,
        totalGainsLinear,
        totalGainsQuadratic
        
    };
    
    // ================================================================
    // Values
    
    
    // energy
    constexpr float startValEnergy                  {0.1f};
    constexpr float endValEnergy                    {10.f};
    constexpr float incrementEnergy                 {0.1f};
    constexpr float defaultEnergy                   {5.f};
    constexpr float skewEnergy                      {1.f};
    
    // radialIntensity
    constexpr float startValRadialIntensity         {0.1f};
    constexpr float endValRadialIntensity           {10.f};
    constexpr float incrementRadialIntensity        {0.1f};
    constexpr float defaultRadialIntensity          {5.f};
    constexpr float skewRadialIntensity             {1.f};
    
    // transverseIntensity
    constexpr float startValTransverseIntensity     {0.1f};
    constexpr float endValTransverseIntensity       {10.f};
    constexpr float defaultTransverseIntensity      {5.f};
    constexpr float incrementTransverseIntensity    {0.1f};
    constexpr float skewTransverseIntensity         {1.f};
    
    // pressure
    constexpr float startValPressure                {0.1f};
    constexpr float endValPressure                  {10.f};
    constexpr float defaultPressure                 {5.f};
    constexpr float incrementPressure               {0.1f};
    constexpr float skewPressure                    {1.f};
    
    // radialVelocity
    constexpr float startValRadialVelocity          {0.1f};
    constexpr float endValRadialVelocity            {10.f};
    constexpr float defaultRadialVelocity           {5.f};
    constexpr float incrementRadialVelocity         {0.1f};
    constexpr float skewRadialVelocity              {1.f};
    
    // transverseVelocity
    constexpr float startValTransverseVelocity      {0.1f};
    constexpr float endValTransverseVelocity        {10.f};
    constexpr float defaultTransverseVelocity       {5.f};
    constexpr float incrementTransverseVelocity     {0.1f};
    constexpr float skewTransverseVelocity          {1.f};

    // inPhaseQuadratic
    constexpr float startValInPhaseQuadratic        {0.1f};
    constexpr float endValInPhaseQuadratic          {10.f};
    constexpr float defaultInPhaseQuadratic         {5.f};
    constexpr float incrementInPhaseQuadratic       {0.1f};
    constexpr float skewInPhaseQuadratic            {1.f};

    // symmetryQuadratic
    constexpr float startValSymmetryQuadratic       {0.1f};
    constexpr float endValSymmetryQuadratic         {10.f};
    constexpr float defaultSymmetryQuadratic        {5.f};
    constexpr float incrementSymmetryQuadratic      {0.1f};
    constexpr float skewSymmetryQuadratic           {1.f};

    // inPhaseLinear
    constexpr float startValInPhaseLinear           {0.1f};
    constexpr float endValInPhaseLinear             {10.f};
    constexpr float defaultInPhaseLinear            {5.f};
    constexpr float incrementInPhaseLinear          {0.1f};
    constexpr float skewInPhaseLinear               {1.f};

    // symmetryLinear
    constexpr float startValSymmetryLinear          {0.1f};
    constexpr float endValSymmetryLinear            {10.f};
    constexpr float defaultSymmetryLinear           {5.f};
    constexpr float incrementSymmetryLinear         {0.1f};
    constexpr float skewSymmetryLinear              {1.f};

    // totalGainsLinear
    constexpr float startValTotalGainsLinear        {0.1f};
    constexpr float endValTotalGainsLinear          {10.f};
    constexpr float defaultTotalGainsLinear         {5.f};
    constexpr float incrementTotalGainsLinear       {0.1f};
    constexpr float skewTotalGainsLinear            {1.f};

    // totalGainsQuadratic
    constexpr float startValTotalGainsQuadratic     {0.1f};
    constexpr float endValTotalGainsQuadratic       {10.f};
    constexpr float defaultTotalGainsQuadratic      {5.f};
    constexpr float incrementTotalGainsQuadratic    {0.1f};
    constexpr float skewTotalGainsQuadratic         {1.f};
    
    
    const std::unordered_map<juce::String, float> defaultValues
    {
        {energy, defaultEnergy},
        {radialIntensity, defaultRadialIntensity},
        {transverseIntensity, defaultTransverseIntensity},
        {pressure, defaultPressure},
        {radialVelocity, defaultRadialVelocity},
        {transverseVelocity, defaultTransverseVelocity},
        {inPhaseQuadratic, defaultInPhaseQuadratic},
        {symmetryQuadratic, defaultInPhaseQuadratic},
        {inPhaseLinear, defaultInPhaseLinear},
        {symmetryLinear, defaultSymmetryLinear},
        {totalGainsLinear, defaultTotalGainsLinear},
        {totalGainsQuadratic, defaultTotalGainsQuadratic}
    };
    
    }

    class PythonParameterNameMap {

    public:
        
        const std::map<juce::String, juce::String>  encodingOptionMap = {
            { EncodingOptions::inputType,                   "input_type"},
            { EncodingOptions::outputType,                  "output_type"},
            { EncodingOptions::ambisonics,                  "ambisonics"},
            { EncodingOptions::surround,                    "surround"},
            { EncodingOptions::Ambisonics::order,           "ambisonics_order"},
            { EncodingOptions::Surround::surroundLayout,    "surroundLayout"}
        };
        
        const std::map<juce::String, juce::String>  coefficientMap = {
            { Coeffs::energy,                               "energy" },
            { Coeffs::radialIntensity,                      "radial_intensity" },
            { Coeffs::transverseIntensity,                  "transverse_intensity" },
            { Coeffs::pressure,                             "pressure" },
            { Coeffs::radialVelocity,                       "radial_velocity" },
            { Coeffs::transverseVelocity,                   "transverse_velocity" },
            { Coeffs::inPhaseQuadratic,                     "in_phase_quad" },
            { Coeffs::symmetryQuadratic,                    "symmetry_quad" },
            { Coeffs::inPhaseLinear,                        "in_phase_lin" },
            { Coeffs::symmetryLinear,                       "symmetry_lin" },
            { Coeffs::totalGainsLinear,                     "total_gains_lin" },
            { Coeffs::totalGainsQuadratic,                  "total_gains_quad" }
        };
    };
}
