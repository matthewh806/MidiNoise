/*
  ==============================================================================

    AudioPlayerComponent.cpp
    Created: 2 Sep 2018 7:59:31pm
    Author:  Matthew

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioPlayerComponent.h"
#include <stdlib.h>

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
    transportSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void AudioPlayerComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo &buffer)
{
    if(readerSource.get() == nullptr) {
        buffer.clearActiveBufferRegion();
        return;
    }
    
    transportSource.getNextAudioBlock(buffer);
}

void AudioPlayerComponent::releaseResources()
{
    transportSource.releaseResources();
}

//==============================================================================

void AudioPlayerComponent::playSampleAudio()
{
    Logger::getCurrentLogger()->writeToLog("Play audio file!");
    
    // TODO: For maximum fun and useability... don't hardcode this!
    
    auto filePath = "~/Projects/juce/MidiNoise/Assets";
    
    File* file = new File(filePath);
    
    Array<File> files;
    if(file->isDirectory())
    {
        Logger::getCurrentLogger()->writeToLog("Path is directory");
        files = file->findChildFiles(2, false);
    } else if(file->existsAsFile()) {
        Logger::getCurrentLogger()->writeToLog("Path is file");
        files.add(*file);
    } else {
        // TODO: log something.
    }
    
    auto idx = rand() % files.size() ;
    auto* reader = formatManager.createReaderFor(files[idx]);
 
    if(reader == nullptr) {
        // TODO: Do some error handling?
        return;
    }
    
    auto duration = reader->lengthInSamples / reader->sampleRate;
    
    std::unique_ptr<AudioFormatReaderSource> newSource(new AudioFormatReaderSource(reader, true));
    transportSource.setSource(newSource.get(), 0, nullptr, reader->sampleRate);
    transportSource.setPosition(0.0);
    transportSource.start();
    readerSource.reset(newSource.release());
    
    Logger::getCurrentLogger()->writeToLog(std::to_string(duration));
}
