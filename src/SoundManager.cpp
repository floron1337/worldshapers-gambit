//
// Created by floron on 5/16/25.
//

#include "../headers/SoundManager.h"

SoundManager::SoundManager(const float volume_): next_card_sound("next_card.mp3"), reverse_card_sound("reverse_card.mp3") {
    volume = volume_;
}

void SoundManager::playNextCardSound(){
    next_card_sound.play();
}

void SoundManager::playReverseCardSound() {
    reverse_card_sound.play();
}
