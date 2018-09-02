/*
  ==============================================================================

    RangeSettingsPages.cpp
    Created: 2 Sep 2018 6:52:14pm
    Author:  Matthew

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "RangeSettingsPages.h"

//==============================================================================
RangeSettingsPages::RangeSettingsPages()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

RangeSettingsPages::~RangeSettingsPages()
{
}

void RangeSettingsPages::paint (Graphics& g)
{
    g.fillAll (Colours::palegreen);
    
    Rectangle<float> area(10, 10, 180, 380);
    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 5.0f, 2.0f);
}

void RangeSettingsPages::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
