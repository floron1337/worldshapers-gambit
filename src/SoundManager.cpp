//
// Created by floron on 5/16/25.
//

#include "../headers/SoundManager.h"
#include <filesystem>

#include "../headers/Constants.h"
#include "../headers/Exception.h"
namespace fs = std::filesystem;

SoundManager::SoundManager(sf::RenderWindow &window_, const float volume_): window(window_), next_card_sound("./sounds/effects/next_card.mp3"), reverse_card_sound("./sounds/effects/reverse_card.mp3") {
    volume = volume_;
    next_card_sound.setVolume(volume);
    reverse_card_sound.setVolume(volume);

    loadMusic();

    for (const auto song: music_list) {
        song->setVolume(volume);
    }
}

SoundManager::~SoundManager() {
    for (const auto music : music_list) {
        delete music;
    }
}

void SoundManager::playNextCardSound(){
    next_card_sound.play();
}

void SoundManager::playReverseCardSound() {
    reverse_card_sound.play();
}

void SoundManager::loadMusic() {
    for (const auto & entry : fs::directory_iterator(Constants::MUSIC_LOCATION)) {
        auto* to_add = new Music(entry.path());
        music_list.push_back(to_add);
        music_map[entry.path().stem().string()] = to_add;
    }
}


void SoundManager::loadMusic(const std::string& music_location) {
    for (const auto & entry : fs::directory_iterator(music_location)) {
        auto* to_add = new Music(entry.path());
        music_list.push_back(to_add);
        music_map[entry.path().stem().string()] = to_add;
    }
}

void SoundManager::playMusic(const int music_index) {
    if (current_music)
        current_music->stop();

    if (music_index >= static_cast<int>(music_list.size()) || music_index < 0) {
        throw MusicOutOfBounds(music_index);
    }
    music_list[music_index]->play();
    current_music = music_list[music_index];
}

void SoundManager::playMusic(const std::string &music_name) {
    if (current_music)
        current_music->stop();

    if (!music_map.contains(music_name))
        throw InvalidMusic(music_name);

    music_map[music_name]->play();
    current_music = music_map[music_name];
}
