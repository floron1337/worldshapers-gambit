//
// Created by floron on 5/3/25.
//

#ifndef ENUMS_H
#define ENUMS_H
#include <string>

namespace Constants {
    static constexpr int GAME_FPS = 60;
    const inline static std::string GAME_DATA_PACKS_LOCATION = "./game_packs.txt";
    const inline static std::string MUSIC_LOCATION  = "./sounds/music/";

    enum ScreensEnum {
        Menu,
        Settings,
        Game,
        Ending,
    };

    enum GFXState {
        Idle,
        ChangingCard,
        Flipping,
    };

    enum SwipeDirection {
        Left,
        Right,
    };

    enum GameRNGValues {
        Finances,
        Popularity,
        Power,
        Industry,
    };

    enum EndingType {
        None,
        OldAge,
        Resignation,
        Assasination,
        Eclipse,
        Omniterra,
        Legion,
        Cult,
    };
};



#endif //ENUMS_H
