/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "BitRedux.h"
#include "PluginProcessor.h"
#include "Knob1.h"

//==============================================================================
/**
*/
class BitReduxAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                      public juce::Slider::Listener
{
public:
    BitReduxAudioProcessorEditor (BitReduxAudioProcessor&);
    ~BitReduxAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider * slider) override;
    
    
    juce::Slider numBits;
    
    Knob1 knob1;

private:
    
    BitRedux BitRedux;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    BitReduxAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BitReduxAudioProcessorEditor)
};
