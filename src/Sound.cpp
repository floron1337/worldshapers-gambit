//
// Created by floron on 5/20/25.
//

#include "../headers/Sound.h"

#include <iostream>
#include <SFML/Audio.hpp>

#include "../headers/Constants.h"
#include "../headers/Exception.h"

Sound::Sound(const fs::path &sound_path_) : sound_name(sound_path_) {
    sound_extenstion = sound_path_.extension().string();
    sound_name = sound_path_.stem().string();
}

Music::Music(const std::string &song_path_) : Sound(song_path_) {
    if (!music.openFromFile(song_path_)) {
        throw InvalidMusic(song_path_);
    }
}

void Music::play() {
    music.play();
}

SoundEffect::SoundEffect(const std::string &sound_name_) : Sound(sound_name_) {
    if (!sound_buffer.loadFromFile("./sounds/effects/" + sound_name_)) {
        throw InvalidSoundEffect(sound_name_);
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

