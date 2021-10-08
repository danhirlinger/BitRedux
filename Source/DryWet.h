/*
  ==============================================================================

    DryWet.h
    Created: 8 Oct 2021 8:38:08am
    Author:  Dan Hirlinger

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class DryWet{
    
public:
    DryWet(){};
    ~DryWet(){};
    
    void setDryWet(float newRatio){
        ratio = newRatio;
    };
    
    float processSample(float dry, float wet){
        float y = ((1-ratio)*dry) + (ratio*wet);
        return y;
    };
    
    void processBuffer(){};
    
private:
    
    float ratio = 0.5f; // 0=dry; 1=wet
}
