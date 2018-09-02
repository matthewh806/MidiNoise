/*
  ==============================================================================

    MidiSettingsPages.h
    Created: 2 Sep 2018 6:42:27pm
    Author:  Matthew

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class MidiSettingsPages    : public Component
{
public:
    TextButton makeNoiseButton; // Make this an image button eventually
    
    MidiSettingsPages();
    ~MidiSettingsPages();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiSettingsPages)
};
