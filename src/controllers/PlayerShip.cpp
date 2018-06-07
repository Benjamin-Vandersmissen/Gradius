//
// Created by benji on 09.12.17.
//

#include "PlayerShip.h"

void controllers::PlayerShip::update() {
    float dx = sf::Keyboard::isKeyPressed(sf::Keyboard::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    float dy = sf::Keyboard::isKeyPressed(sf::Keyboard::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    m_currentDirection = {dx,dy};

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        fire();
    }
    Ship::update();
}

void controllers::PlayerShip::handleEvent(const sf::Event &event) {

}