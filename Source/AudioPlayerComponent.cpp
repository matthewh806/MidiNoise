/*
  ==============================================================================

    AudioPlayerComponent.cpp
    Created: 2 Sep 2018 7:59:31pm
    Author:  Matthew

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioPlayerComponent.h"

//==============================================================================
AudioPlayerComponent::AudioPlayerComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

AudioPlayerComponent::~AudioPlayerComponent()
{
}

//==============================================================================

void AudioPlayerComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
    
}

void AudioPlayerComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo &buffer)
{
    
}

void AudioPlayerComponent::releaseResources()
{
    // TODO: Release resources!
}

//==============================================================================

void AudioPlayerComponent::playSampleAudio()
{
    Logger::getCurrentLogger()->writeToLog("Play audio file!");
}
