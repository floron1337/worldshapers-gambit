//
// Created by floron on 5/15/25.
//

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>


class Exception : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class CardOutOfBounds : public Exception {
public:
    explicit CardOutOfBounds(const std::string& pack, int card_index);
};

class TextureNotFound : public Exception {
public:
    explicit TextureNotFound(const std::string& texture_location);
};

class InvalidScreenId : public Exception {
public:
    explicit InvalidScreenId(int screen_id);
};

class InvalidCardPack : public Exception {
public:
    explicit InvalidCardPack(const std::string& pack_name);
};

class MissingGameData : public Exception {
public:
    explicit MissingGameData();
};

class InvalidCardGFXState : public Exception {
public:
    explicit InvalidCardGFXState(int state);
};

class InvalidSoundEffect : public Exception {
public:
    explicit InvalidSoundEffect(const std::string& sound_name);
};

class InvalidMusic : public Exception {
public:
    explicit InvalidMusic(const std::string& music_name);
};

class MusicOutOfBounds : public Exception {
public:
    explicit MusicOutOfBounds(int index);
};

#endif //EXCEPTIONS_H
