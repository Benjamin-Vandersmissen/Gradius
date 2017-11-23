//
// Created by benji on 22.11.17.
//

#include <iostream>
#include "PlayerShip.h"
#include "Transformation.h"

void controllers::Playership::update() {
    float dx = sf::Keyboard::isKeyPressed(sf::Keyboard::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    float dy = sf::Keyboard::isKeyPressed(sf::Keyboard::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    m_currentDirection = {dx,dy};

    if(m_currentDirection != std::pair<float,float>{0,0}){
        notify();
    }
}

const std::pair<float, float> &controllers::Playership::currentDirection() const {
    return m_currentDirection;
}

void models::Playership::update() {
    auto controller = std::dynamic_pointer_cast<controllers::Playership>(m_controller);
    if(controller) {
        m_position.first += m_speed*controller->currentDirection().first;
        m_position.second += m_speed*controller->currentDirection().second;
        notify();
    }
}

void views::PlayerShip::update() {
    std::cout << "Position is :" << m_model->position().first << ' ' << m_model->position().second << std::endl;
    Entity::update();
}

void views::PlayerShip::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(m_animation, states);
}
