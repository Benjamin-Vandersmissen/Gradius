//
// Created by benji on 13.11.17.
//

#include "PlayerShip.h"

void entities::PlayerShip::handleEvent(sf::Event &event) {
    switch(event.type) {
        case sf::Event::KeyPressed:
            handleKeyboard(event);
        default:
            break;
    }
}

void entities::PlayerShip::handleKeyboard(sf::Event &event) {
    switch(event.key.code){
        case sf::Keyboard::Space:
            //fire
            int fire;
            break;

        default:
            break;
    }
}


void entities::PlayerShip::update() {
    bool keyUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    bool keyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    bool keyRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    bool keyLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);

    std::pair<double, double> desiredDirection = {m_speed*(keyRight-keyLeft), m_speed*(keyDown-keyUp)};

//    m_direction = {(m_direction.first + desiredDirection.first)/2, (m_direction.second + desiredDirection.second)/2};
    m_direction = desiredDirection;
    Entity::update();
}

entities::PlayerShip::PlayerShip(const std::pair<float, float> &position, sf::Texture *texture, float speed) : Entity(
        position, texture, speed) {}
