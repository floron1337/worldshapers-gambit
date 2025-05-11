//
// Created by floron on 5/2/25.
//

#include "../headers/Screen.h"

Screen::Screen(sf::RenderWindow *window_, ScreenManager *screen_manager_) : window(window_), screen_manager(screen_manager_){

}

Screen& Screen::operator=(const Screen& other) {
    if (this == &other) {
        return *this;
    }

    window = other.window;
    screen_manager = other.screen_manager;

    return *this;
}

Screen::Screen(const Screen& other) {
    window = other.window;
    screen_manager = other.screen_manager;
}