/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...
    AudioDeviceManager deveiceManager;
    
    ComboBox midiOutputList;
    Label midiOutputListLabel;
    
    ComboBox arpegiatorToggle;
    Label arpeggiatorToggleLabel;
    
    ComboBox latchToggle;
    Label latchToggleLabel;
    
    ComboBox legatoToggle;
    Label lagatoToggleLabel;
    
    ComboBox midiClock;
    Label midiClockLabel;
    
    MidiOutput *output = nullptr;
    
    //==============================================================================
    void setMidiOutput(int index);
    void setArpegiatorState(int value);
    void setLatchState(int value);
    void sendMidiMessage(int channel, int type, int value);
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
