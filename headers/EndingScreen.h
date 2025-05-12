//
// Created by floron on 5/12/25.
//

#ifndef ENDINGSCREEN_H
#define ENDINGSCREEN_H
#include "Screen.h"
#include <SFML/Graphics.hpp>

#include "Constants.h"

class ScreenManager;

class EndingScreen : public Screen{
    Constants::EndingType ending_type;
    std::string ending_text1_str;
    std::string ending_text2_str;
    std::string ending_text3_str;

    std::string getEndingText1() const;
    std::string getEndingText2() const;
    std::string getEndingText3() const;
    void drawEndingText() const;
public:
    explicit EndingScreen(sf::RenderWindow *window_, ScreenManager *screen_manager_);
    void drawScreen() override;
};



#endif //ENDINGSCREEN_H
