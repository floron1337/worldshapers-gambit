//
// Created by floron on 5/20/25.
//

#include "../headers/Sound.h"

#include <iostream>
#include <SFML/Audio.hpp>

#include "../headers/Constants.h"
#include "../headers/Exception.h"

Sound::Sound(const fs::path &sound_path_) : sound_path(sound_path_.string()), sound_name(sound_path_.stem()), sound_extenstion(sound_path_.extension().string()){
}

Music::Music(const fs::path &song_path_) : Sound(song_path_) {
    if (!music.openFromFile(song_path_)) {
        throw InvalidMusic(song_path_);
    }
}

void Music::play() {
    music.play();
}

SoundEffect::SoundEffect(const fs::path &sound_path_) : Sound(sound_path_) {
    if (!sound_buffer.loadFromFile(sound_path_)) {
        throw InvalidSoundEffect(sound_path_);
    }
    sound = sf::Sound(sound_buffer);
}

void SoundEffect::play() {
    sound.play();
}

void SoundEffect::setVolume(float volume) {
    sound.setVolume(volume);
}

void Music::setVolume(float volume) {
    music.setVolume(volume);
}

