/*
  ==============================================================================

    MidiSettingsPages.cpp
    Created: 2 Sep 2018 6:42:27pm
    Author:  Matthew

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MidiSettingsPages.h"

//==============================================================================
MidiSettingsPages::MidiSettingsPages()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    addAndMakeVisible(makeNoiseButton);
    makeNoiseButton.setButtonText("MAKE NOISE!");
}

MidiSettingsPages::~MidiSettingsPages()
{
}

void MidiSettingsPages::paint (Graphics& g)
{
    g.fillAll(Colours::lightblue);
    
    Rectangle<float> area(10, 10, getWidth()-20, getHeight()-20);
    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 5.0f, 2.0f);
}

void MidiSettingsPages::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    auto area = getLocalBounds().reduced(10);
    makeNoiseButton.setBounds(area.removeFromBottom(50).reduced(80, 0));

}
