//
// Created by floron on 5/15/25.
//

#include "../headers/Exception.h"

CardOutOfBounds::CardOutOfBounds(const std::string& pack, const int card_index) : Exception(pack + " Card index out of bounds: " + std::to_string(card_index)) {}
TextureNotFound::TextureNotFound(const std::string& texture_location) : Exception("Texture not found at: " + texture_location) {}
InvalidScreenId::InvalidScreenId(const int screen_id) : Exception("Invalid screen id: " + screen_id) {}
InvalidCardPack::InvalidCardPack(const std::string& pack_name) : Exception("Invalid card pack name: " + pack_name) {}
MissingGameData::MissingGameData() : Exception("Missing game data file") {}
InvalidCardGFXState::InvalidCardGFXState(const int state) : Exception("Invalid card gfx state: " + std::to_string(state)) {}
InvalidSoundEffect::InvalidSoundEffect(const std::string& sound_name) : Exception("Invalid sound effect: " + sound_name) {}
InvalidMusic::InvalidMusic(const std::string& music_name) : Exception("Invalid music: " + music_name) {}