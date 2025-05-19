//
// Created by floron on 5/20/25.
//

#ifndef SOUND_H
#define SOUND_H
#include <string>

#include "SFML/Audio/Music.hpp"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"


class Sound {
    std::string sound_name;
public:
    explicit Sound(const std::string& sound_name_);
    virtual ~Sound() = default;
    virtual void play() = 0;
};

class Music : public Sound {
    sf::Music music;
public:
    Music(const std::string& sound_name_);
    void play() override;
};

class SoundEffect : public Sound {
    sf::SoundBuffer sound_buffer;
    sf::Sound sound;
public:
    explicit SoundEffect(const std::string& song_name_);
    void play() override;
};

#endif //SOUND_H
