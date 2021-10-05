/*
  ==============================================================================

    BitRedux.h
    Created: 16 Apr 2021 11:12:42am
    Author:  Dan Hirlinger

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include <cmath>

class BitRedux{
public:
    BitRedux(); ~BitRedux();
    
    void prepare(const juce::dsp::ProcessSpec& spec);
    
    float processSample(float x);
    
    // juce::AudioBuffer<float> &buffer
    void processSignal(juce::AudioBuffer<float> &buffer);
    
    void createDither();
    
    void setAmpLevels();
    
    int Fs;
    int C;
    int N;
    int M; // number of bits
    float dryWet = 0.f; // 0 = dry ; 1 = wet
    float ditherFactor = 0.001f;
    
private:   
    
    float xProcess;
    int ampLevels; // 2^M
    float dither;

};


