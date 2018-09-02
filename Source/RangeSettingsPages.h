/*
  ==============================================================================

    RangeSettingsPages.h
    Created: 2 Sep 2018 6:52:14pm
    Author:  Matthew

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class RangeSettingsPages    : public Component
{
public:
    RangeSettingsPages();
    ~RangeSettingsPages();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RangeSettingsPages)
};
