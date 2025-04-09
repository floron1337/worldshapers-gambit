#ifndef GAME_H
#define GAME_H



class Game {
    unsigned max_fps;

public:
    Game();
    explicit Game(int max_fps_);
    ~Game();

    void start();
};



#endif //GAME_H
