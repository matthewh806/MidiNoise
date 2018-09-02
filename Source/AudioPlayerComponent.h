/*
  ==============================================================================

    AudioPlayerComponent.h
    Created: 2 Sep 2018 7:59:31pm
    Author:  Matthew

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class AudioPlayerComponent    : public AudioAppComponent
{
public:
    AudioPlayerComponent();
    ~AudioPlayerComponent();
    
    //==============================================================================
    void releaseResources() override;
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock(const AudioSourceChannelInfo& buffer) override;
    
    //==============================================================================
    void playSampleAudio();
    

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPlayerComponent)
};
