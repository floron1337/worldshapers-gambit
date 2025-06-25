#ifndef GAME_H
#define GAME_H
#include <iostream>

#include "ScreenManager.h"
#include "SoundManager.h"

class Game {
    unsigned max_fps = 60;

    sf::RenderWindow window;
    SoundManager sound_manager;
    ScreenManager screen_manager;

    explicit Game(unsigned max_fps_ = 60);
public:
    Game(Game& other) = delete;
    Game& operator=(const Game& other) = delete;

    ~Game() = default;
    void start();
    //void set_max_fps(unsigned max_fps_) { max_fps = max_fps_; }
    static Game& getInstance();
};

#endif //GAME_H
