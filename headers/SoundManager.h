//
// Created by floron on 5/16/25.
//

#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include <map>
#include <vector>

#include "Sound.h"

class SoundManager {
    Music *current_music = nullptr;
    std::vector<Music*> music_list;
    std::map<std::string, Music*> music_map;

    SoundEffect next_card_sound;
    SoundEffect reverse_card_sound;
    float volume = 50.0f;

public:
    explicit SoundManager(float volume_ = 50);
    SoundManager(const SoundManager&) = delete;
    SoundManager& operator=(const SoundManager&) = delete;
    ~SoundManager();

    void playNextCardSound();
    void playReverseCardSound();

    void loadMusic();
    void loadMusic(const std::string& music_location);

    void playMusic(int music_index);
    void playMusic(const std::string& music_name);
};



#endif //SOUNDMANAGER_H
