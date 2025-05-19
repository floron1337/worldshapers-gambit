//
// Created by floron on 5/20/25.
//

#include "../headers/Sound.h"
#include <SFML/Audio.hpp>

#include "../headers/Exception.h"

Sound::Sound(const std::string &sound_name_) : sound_name(sound_name_) {

}

Music::Music(const std::string &song_name_) : Sound(song_name_) {
    if (!music.openFromFile("./sounds/music/" + song_name_)) {
        throw InvalidMusic(song_name_);
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
