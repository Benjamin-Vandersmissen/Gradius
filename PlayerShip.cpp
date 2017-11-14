//
// Created by benji on 13.11.17.
//

#include <iostream>
#include "PlayerShip.h"
#include "EnemyShip.h"

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
            fire();
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
    if(m_current_cooldown > 0)
        m_current_cooldown--;
}

entities::PlayerShip::PlayerShip(const std::pair<float, float> &position, sf::Texture *texture, float speed) : Entity(
        position, texture, speed) {
    bulletTexture = new sf::Texture();
    bulletTexture->loadFromFile("../NES - Gradius - Gradius.png", {51,154,8,4});
}

void entities::PlayerShip::fire() {
    if (m_current_cooldown == 0) {
        entityList.insert(entityList.begin(),
                new PlayerBullet({this->m_position.first + 4 + m_direction.first, this->m_position.second + 8 + m_direction.second}, bulletTexture, 8));
        m_current_cooldown = m_cooldown;
    }
}

void entities::PlayerShip::onCollision(Entity *entity) {
    EnemyShip* enemyShip = dynamic_cast<EnemyShip*>(entity);
    if(enemyShip){
        this->m_lives--;
        enemyShip->destroy();
    }
}
