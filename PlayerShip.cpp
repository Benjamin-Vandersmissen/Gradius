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
    if(m_fired){
        notify();
        m_fired = false;
    }
    if(m_fireCooldown > 0){
        m_fireCooldown--;
    }
}

const std::pair<float, float> &controllers::Playership::currentDirection() const {
    return m_currentDirection;
}

void controllers::Playership::handleEvent(const sf::Event &event) {
    switch(event.type){
        case sf::Event::KeyPressed:{
            switch(event.key.code){
                case sf::Keyboard::Space:{
                    if(m_fireCooldown == 0){
                        m_fireCooldown = m_maxFireCooldown;
                        m_fired = true;
                    }
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

bool controllers::Playership::fired() {
    return m_fired;
}

void models::Playership::update() {
    auto controller = std::dynamic_pointer_cast<controllers::Playership>(m_controller);
    if(controller) {
        if(controller->currentDirection() != std::pair<float, float>{0,0}) {
            m_position.first += m_speed * controller->currentDirection().first;
            m_position.second += m_speed * controller->currentDirection().second;
            notify();
        }
        if(controller->fired()){
            std::cout << "Fired a bullet from ship " << this << std::endl;
            //create a bullet
        }
    }
}

void views::PlayerShip::update() {
    std::cout << "Position is :" << m_model->position().first << ' ' << m_model->position().second << std::endl;
    Entity::update();
}

void views::PlayerShip::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(m_animation, states);
}
