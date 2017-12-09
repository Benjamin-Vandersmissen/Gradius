//
// Created by benji on 09.12.17.
//

#include "PlayerShip.h"

void controllers::PlayerShip::update() {
    float dx = sf::Keyboard::isKeyPressed(sf::Keyboard::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    float dy = sf::Keyboard::isKeyPressed(sf::Keyboard::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    m_currentDirection = {dx,dy};

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if(m_fireCooldown == 0){
            m_fired = true;
            m_fireCooldown = m_maxFireCooldown;
        }
    }
    notify();

    m_fired = false;

    if(m_fireCooldown > 0){
        m_fireCooldown--;
    }
}

const std::pair<float, float> &controllers::PlayerShip::currentDirection() const {
    return m_currentDirection;
}

void controllers::PlayerShip::handleEvent(const sf::Event &event) {

}

bool controllers::PlayerShip::fired() {
    return m_fired;
}