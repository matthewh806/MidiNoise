/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================

// TODO: Add constant annoying nosise
// TODO: Button to turn it off (stop making noise)
// TODO: Button "stop making sense" with david byrne all over the place and other annoying stuff

/// ^^ If anybody ever reads this, this is what I think is funny in software. Horror or Dadaist software.

MainComponent::MainComponent()
{
    setSize (600, 400);
    
    addAndMakeVisible(midiOutputListLabel);
    midiOutputListLabel.setText("MIDI output:", dontSendNotification);
    midiOutputListLabel.attachToComponent(&midiOutputList, true);
    
    addAndMakeVisible(midiOutputList);
    midiOutputList.setTextWhenNoChoicesAvailable("No MIDI outputs enabled");
    
    auto midiOutputs = MidiOutput::getDevices();
    
    midiOutputList.addItemList(midiOutputs, 1);
    midiOutputList.onChange = [this] { setMidiOutput(midiOutputList.getSelectedId() - 1); };
    
    addAndMakeVisible(arpeggiatorToggleLabel);
    arpeggiatorToggleLabel.setText("Arpegiator", dontSendNotification);
    arpeggiatorToggleLabel.attachToComponent(&arpegiatorToggle, true);
    
    arpegiatorToggle.addItem("off", 1);
    arpegiatorToggle.addItem("on", 2);
    arpegiatorToggle.onChange = [this] { setArpegiatorState(arpegiatorToggle.getSelectedId() - 1);};
    addAndMakeVisible(arpegiatorToggle);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("MAKE MIDI NOISE!", getLocalBounds(), Justification::centred, true);
}

void MainComponent::resized()
{
    auto area = getLocalBounds();
    
    midiOutputList.setBounds(area.removeFromTop(36).removeFromRight(getWidth()-150).reduced(8));
    arpegiatorToggle.setBounds(area.removeFromTop(36).removeFromRight(getWidth()-150).reduced(8));
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

void MainComponent::setArpegiatorState(int value)
{
    if(output == nullptr)
    {
        // TODO: Log a warning here and try to reconnect?
    }
    
    // TODO: Change this midi note to 117 for arpegiator state (this is an easier initial testing value)
    MidiMessage message = MidiMessage::controllerEvent(2, 119, value);
    output->sendMessageNow(message);
}
