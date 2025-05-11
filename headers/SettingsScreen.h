//
// Created by floron on 5/11/25.
//

#ifndef SETTINGSSCREEN_H
#define SETTINGSSCREEN_H
#include "Screen.h"


class ScreenManager;

class SettingsScreen : public Screen{
public:
    explicit SettingsScreen(sf::RenderWindow *window_, ScreenManager *screen_manager_);
    void drawScreen() override;
};



#endif //SETTINGSSCREEN_H
