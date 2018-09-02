/*
  ==============================================================================

    GeneralPages.h
    Created: 27 Aug 2018 11:19:59pm
    Author:  Matthew

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
//==============================================================================
/*
*/
class GeneralPages    : public Component
{
public:
    ComboBox midiOutputList;
    ComboBox arpegiatorToggle;
    ComboBox latchToggle;
    ComboBox legatoToggle;
    ComboBox midiClock;
    
    GeneralPages();
    ~GeneralPages();

    void paint (Graphics&) override;
    void resized() override;

private:
    Label midiOutputListLabel;
    
    Label arpeggiatorToggleLabel;
    
    Label latchToggleLabel;
    
    Label lagatoToggleLabel;
    
    Label midiClockLabel;    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GeneralPages)
};
