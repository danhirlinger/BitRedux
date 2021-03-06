/*
  ==============================================================================

    BitRedux.cpp
    Created: 16 Apr 2021 11:12:42am
    Author:  Dan Hirlinger

  ==============================================================================
*/

#include "BitRedux.h"

BitRedux::BitRedux(){
}
BitRedux::~BitRedux(){
}

void BitRedux::prepare(const juce::dsp::ProcessSpec &spec){
    Fs = spec.sampleRate;
    C = spec.numChannels;
    N = spec.maximumBlockSize;
    M = 16.f;
    setAmpLevels(M);
}

float BitRedux::processSample(float x){
    createDither();
    xProcess = x + dither;
    
    // Change scale [-1:1] >> [0:1]
    xProcess = (0.5f * x) + 0.5f;
    
    // Multiply by # of ampLevels (from parameter)
    xProcess = ampLevels * xProcess;
    xProcess = round(xProcess);

    // Divide by ampLevels to return to range [0:1]
    xProcess = xProcess * (1.f/ampLevels);

    // Revert scale [0:1] >> [-1:1]
    xProcess = (xProcess * 2.f) - 1.f;
    
    // figure out dry/wet
//    xProcess = (dryWet*xProcess) + ((dryWet-1)*x);
    
    return xProcess;
}

void BitRedux::processSignal(juce::AudioBuffer<float> &buffer){
    for (int c = 0; c < C; c++){
        for (int n = 0; n < N; n++){
            float in = buffer.getReadPointer(c)[n];
            float x = processSample(in);
            buffer.getWritePointer(c)[n] = x;
            // want to add dry/wet capabilities
            // (dryWet*x) + ((dryWet-1)*(in))
        }
    }
}

void BitRedux::createDither(){
// Create dither to be added to signal
    dither = ditherFactor * ((rand() * 2.f) - 1.f);
//    dither = 0;
}

void BitRedux::setAmpLevels(int newM){
    ampLevels = 2^newM;
}


