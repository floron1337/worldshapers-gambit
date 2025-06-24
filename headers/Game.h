#ifndef GAME_H
#define GAME_H

class Game {
    inline static unsigned max_fps = 60;
    inline static Game* instance = nullptr;

    explicit Game(int max_fps_ = 60);
public:
    ~Game();
    static void start();
};

#endif //GAME_H
