/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "GeneralPages.h"
#include "MidiSettingsPages.h"
#include "RangeSettingsPages.h"
#include "AudioPlayerComponent.h"

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
    
    AudioPlayerComponent audioPlayer;
    
    GeneralPages generalPages;
    MidiSettingsPages midiSettingsPages;
    RangeSettingsPages rangeSettingsPages;
    
    void setMidiOutput(int value);
    void sendMidiMessage(int channel, int type, int value);
    
    MidiOutput *output = nullptr;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
