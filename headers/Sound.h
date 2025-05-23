//
// Created by floron on 5/20/25.
//

#ifndef SOUND_H
#define SOUND_H
#include <string>
#include <SFML/Audio.hpp>
#include <filesystem>
namespace fs = std::filesystem;

class Sound {
    std::string sound_path;
    std::string sound_name;
    std::string sound_extenstion;
public:
    explicit Sound(const fs::path& sound_path_);
    virtual ~Sound() = default;
    virtual void play() = 0;
    virtual void stop() = 0;
    virtual void setVolume(float volume) = 0;
};

class Music : public Sound {
    sf::Music music;
public:
    explicit Music(const fs::path& song_path_);
    void play() override;
    void stop() override;
    void setVolume(float volume) override;
};

class SoundEffect : public Sound {
    sf::SoundBuffer sound_buffer;
    sf::Sound sound;
public:
    explicit SoundEffect(const fs::path& sound_path_);
    void play() override;
    void stop() override;
    void setVolume(float volume) override;
};

#endif //SOUND_H
