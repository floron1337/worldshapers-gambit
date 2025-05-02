//
// Created by floron on 5/2/25.
//

#include "../headers/Screen.h"

Screen::Screen(sf::RenderWindow &window_, ScreenManager *screen_manager_) : window(window_){
    screen_manager = screen_manager_;
}
