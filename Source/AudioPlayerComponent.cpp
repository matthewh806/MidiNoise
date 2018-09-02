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
    formatManager.registerBasicFormats();
    
    // TODO: Maybe register this as class ChangeListener?
    
    
    setAudioChannels(0, 2);
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
    
    // TODO: For maximum fun and useability... don't hardcode this!
    File* file = new File("~/Documents/Music/samples/dead_ends.wav");
    std::unique_ptr<AudioFormatReader> reader(formatManager.createReaderFor(*file));
 
    if(reader.get() == nullptr) {
        // TODO: Do some error handling?
        return;
    }
    
    auto duration = reader->lengthInSamples / reader->sampleRate;
    
    Logger::getCurrentLogger()->writeToLog(std::to_string(duration));
}
