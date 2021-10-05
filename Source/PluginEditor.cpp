/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
BitReduxAudioProcessorEditor::BitReduxAudioProcessorEditor (BitReduxAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    numBits.addListener(this);
    numBits.setBounds(70, 65, 150, 150);
    numBits.setSize(80, 100);
    numBits.setRange(2,16,1);
    numBits.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    numBits.setTextBoxStyle(Slider::TextBoxBelow, false, 75, 25);
    numBits.setValue(BitRedux.M);
    numBits.setLookAndFeel(&knob1);
    
    addAndMakeVisible(numBits);
}

BitReduxAudioProcessorEditor::~BitReduxAudioProcessorEditor()
{
}

//==============================================================================
void BitReduxAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::whitesmoke);
    
}

void BitReduxAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}


void BitReduxAudioProcessorEditor::sliderValueChanged(juce::Slider * slider){
    if (slider == &numBits){
        BitRedux.M = numBits.getValue();
        BitRedux.setAmpLevels(numBits.getValue());
    }
}
