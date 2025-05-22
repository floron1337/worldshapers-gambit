//
// Created by floron on 5/16/25.
//

#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include <map>
#include <memory>
#include <vector>

#include "Sound.h"

class SoundManager {
    std::vector<Music*> music_list;
    std::map<std::string, Music*> music_map;

    SoundEffect next_card_sound;
    SoundEffect reverse_card_sound;
    float volume = 50.0f;

public:
    explicit SoundManager(float volume_ = 50);
    ~SoundManager();
    void playNextCardSound();
    void playReverseCardSound();
    void loadMusic();
    void loadMusic(const std::string& music_location);
    void playMusic(int music_index) const;
    void playMusic(const std::string& music_name);
};



#endif //SOUNDMANAGER_H
