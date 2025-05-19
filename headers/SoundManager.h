//
// Created by floron on 5/16/25.
//

#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include <vector>

#include "Sound.h"

class SoundManager {
    std::vector<Music> music_list;
    SoundEffect next_card_sound;
    SoundEffect reverse_card_sound;
    float volume = 50.0f;
public:
    explicit SoundManager(float volume_ = 50);
    void playNextCardSound();
    void playReverseCardSound();
};



#endif //SOUNDMANAGER_H
