/*
  ==============================================================================

    GeneralPages.cpp
    Created: 27 Aug 2018 11:19:59pm
    Author:  Matthew

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "GeneralPages.h"

//==============================================================================
GeneralPages::GeneralPages()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    addAndMakeVisible(midiOutputListLabel);
    midiOutputListLabel.setText("MIDI output:", dontSendNotification);
    midiOutputListLabel.attachToComponent(&midiOutputList, true);
    
    addAndMakeVisible(midiOutputList);
    midiOutputList.setTextWhenNoChoicesAvailable("No MIDI outputs enabled");
    
    auto midiOutputs = MidiOutput::getDevices();
    midiOutputList.addItemList(midiOutputs, 1);
    
    addAndMakeVisible(arpeggiatorToggleLabel);
    arpeggiatorToggleLabel.setText("Arpegiator", dontSendNotification);
    arpeggiatorToggleLabel.attachToComponent(&arpegiatorToggle, true);
    
    arpegiatorToggle.addItem("off", 1);
    arpegiatorToggle.addItem("on", 2);
    //    arpegiatorToggle.setText("set");
    addAndMakeVisible(arpegiatorToggle);
    
    addAndMakeVisible(latchToggleLabel);
    latchToggleLabel.setText("Latch", dontSendNotification);
    latchToggleLabel.attachToComponent(&latchToggle, true);
    
    latchToggle.addItem("off", 1);
    latchToggle.addItem("on", 2);
    //    latchToggle.setText("set");
    addAndMakeVisible(latchToggle);
    
    
    addAndMakeVisible(midiClockLabel);
    midiClockLabel.setText("Midi clock", dontSendNotification);
    midiClockLabel.attachToComponent(&midiClock, true);
    
    midiClock.addItem("off", 1);
    midiClock.addItem("on", 2);
    addAndMakeVisible(midiClock);
}

GeneralPages::~GeneralPages()
{
}

void GeneralPages::paint (Graphics& g)
{
    g.fillAll(Colours::lightpink);
    
    Rectangle<float> area(10, 10, 180, 380);
    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 5.0f, 2.0f);
}

void GeneralPages::resized()
{
    auto area = getLocalBounds().reduced(10);
    
    midiOutputList.setBounds(area.removeFromTop(36).removeFromRight(getWidth()-100).reduced(8));
    arpegiatorToggle.setBounds(area.removeFromTop(36).removeFromRight(getWidth()-100).reduced(8));
    latchToggle.setBounds(area.removeFromTop(36).removeFromRight(getWidth()-100).reduced(8));
    midiClock.setBounds(area.removeFromTop(36).removeFromRight(getWidth()-100).reduced(8));
}
