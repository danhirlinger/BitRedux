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
    numBits.setBounds(100, 100, 100, 100);
    numBits.setSize(150, 150);
    numBits.setRange(2,16,1);
    numBits.setValue(BitRedux.M);
    
    addAndMakeVisible(numBits);
}

BitReduxAudioProcessorEditor::~BitReduxAudioProcessorEditor()
{
}

//==============================================================================
void BitReduxAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void BitReduxAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}


void BitReduxAudioProcessorEditor::sliderValueChanged(juce::Slider * slider){
    if (slider == &numBits){
        BitRedux.M = numBits.getValue();
        BitRedux.setAmpLevels();
    }
}
