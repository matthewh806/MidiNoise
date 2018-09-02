/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include <iostream>

//==============================================================================

// TODO: Add constant annoying nosise
// TODO: Button to turn it off (stop making noise)
// TODO: Button "stop making sense" with david byrne all over the place and other annoying stuff

/// ^^ If anybody ever reads this, this is what I think is funny in software. Horror or Dadaist software.

MainComponent::MainComponent()
{
    setSize (600, 400);
    addAndMakeVisible(&generalPages);
    
    generalPages.midiOutputList.onChange = [this]
    {
        setMidiOutput(generalPages.midiOutputList.getSelectedId()-1);
    };
    
    generalPages.arpegiatorToggle.onChange = [this]
    {        
        sendMidiMessage(2, 117, generalPages.arpegiatorToggle.getSelectedId() - 1);
    };
    
    generalPages.latchToggle.onChange = [this]
    {
        sendMidiMessage(2, 119, generalPages.latchToggle.getSelectedId() - 1);
    };
    
    generalPages.midiClock.onChange = [this]
    {
        // TODO: The value here is wrong, fix it!
        sendMidiMessage(2, 119, generalPages.midiClock.getSelectedId() - 1);
    };
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::white);

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
}

void MainComponent::resized()
{
    auto area = getLocalBounds();
    generalPages.setBounds(0, 0, 200, 400);
}

//==============================================================================
void MainComponent::setMidiOutput(int index)
{
    auto list = MidiOutput::getDevices();
    
    // TODO: Check that its the zero coast...
    
    // TODO: Check its in the list again?
    
    // TODO: Close existing?
    output = MidiOutput::openDevice(index);
}

void MainComponent::sendMidiMessage(int channel, int type, int value)
{
    if(output == nullptr)
    {
        // TODO: Log a warning here and try to reconnect?
        Logger::getCurrentLogger()->writeToLog("No output device found!");
        return;
    }
    
    Logger::getCurrentLogger()->writeToLog("I'm here!");
    
    MidiMessage message = MidiMessage::controllerEvent(channel, type, value);
    output->sendMessageNow(message);
}


