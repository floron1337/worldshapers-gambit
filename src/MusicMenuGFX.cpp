//
// Created by floron on 5/22/25.
//

#include "../headers/MusicMenuGFX.h"
#include "../headers/Exception.h"

MusicMenuGFX::MusicMenuGFX(sf::RenderWindow &window_, SoundManager *sound_manager_) : window(window_), sound_manager(sound_manager_) {
    if (!music_button_texture.loadFromFile("./images/music_icon.png") ) {
        throw TextureNotFound("./images/music_icon.png");
    }
    music_button_sprite.setTexture(music_button_texture);
}

void MusicMenuGFX::drawMenu() {
    sound_manager->playMusic(0);
}

void MusicMenuGFX::drawMusicMenu() {
    if (menu_open) {
        drawMenu();
    }
    else {
        drawButton();
    }
}

void MusicMenuGFX::drawButton() {
    music_button_sprite.setScale(0.25f, 0.25f);
    const sf::FloatRect bounds = music_button_sprite.getLocalBounds();
    music_button_sprite.setOrigin(bounds.width / 2.f,  bounds.height);
    music_button_sprite.setPosition(window.getSize().x - 60.0f, 75.0f);
    window.draw(music_button_sprite);
}