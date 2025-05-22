#include <string>
#include <sstream>
#include "../headers/Exception.h"

template<typename T>
std::string to_string_fallback(T value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

CardOutOfBounds::CardOutOfBounds(const std::string& pack, const int card_index)
    : Exception(pack + std::string(" Card index out of bounds: ") + to_string_fallback(card_index)) {}

TextureNotFound::TextureNotFound(const std::string& texture_location)
    : Exception(std::string("Texture not found at: ") + texture_location) {}

InvalidScreenId::InvalidScreenId(const int screen_id)
    : Exception(std::string("Invalid screen id: ") + to_string_fallback(screen_id)) {}

InvalidCardPack::InvalidCardPack(const std::string& pack_name)
    : Exception(std::string("Invalid card pack name: ") + pack_name) {}

MissingGameData::MissingGameData()
    : Exception("Missing game data file") {}

InvalidCardGFXState::InvalidCardGFXState(const int state)
    : Exception(std::string("Invalid card gfx state: ") + to_string_fallback(state)) {}

InvalidSoundEffect::InvalidSoundEffect(const std::string& sound_name)
    : Exception(std::string("Invalid sound effect: ") + sound_name) {}

InvalidMusic::InvalidMusic(const std::string& music_name)
    : Exception(std::string("Invalid music: ") + music_name) {}

MusicOutOfBounds::MusicOutOfBounds(const int index)
    : Exception(std::string("Music index out of bounds at: ") + to_string_fallback(index)) {}