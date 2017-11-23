//
// Created by benji on 22.11.17.
//

#include <iostream>
#include "PlayerShip.h"
#include "Transformation.h"
#include "PlayerBullet.h"

void controllers::PlayerShip::update() {
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

const std::pair<float, float> &controllers::PlayerShip::currentDirection() const {
    return m_currentDirection;
}

void controllers::PlayerShip::handleEvent(const sf::Event &event) {
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

bool controllers::PlayerShip::fired() {
    return m_fired;
}

void models::PlayerShip::update() {
    auto myController = dynamic_cast<controllers::PlayerShip*>(m_controller);
    if(myController) {
        if(myController->currentDirection() != std::pair<float, float>{0,0}) {
            m_position.first += m_speed * myController->currentDirection().first;
            m_position.second += m_speed * myController->currentDirection().second;
            notify();
        }
        if(myController->fired()){
            auto model = new models::PlayerBullet;
            model->position(m_position);
            auto view = new views::PlayerBullet;
            auto controller = new controllers::PlayerBullet;
            view->setModel(model);
            model->setController(controller);
            models::list.push_back(model);
            views::list.push_back(view);
            controllers::list.push_back(controller);
        }
    }
}

void models::PlayerShip::handleCollision(models::Entity *) {
    //collision handling with obstacles and enemy ships
}

void views::PlayerShip::update() {
    Entity::update();
}

void views::PlayerShip::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(m_animation, states);
}

models::PlayerShip *resources::PlayerShip::create() {
    auto model = new models::PlayerShip;
    model->m_speed = m_speed;

    auto view = new views::PlayerShip;
    auto controller = new controllers::PlayerShip;
    model->setController(controller);
    view->setModel(model);

    models::list.push_back(model);
    views::list.push_back(view);
    controllers::list.push_back(controller);
    return model;
}

void resources::PlayerShip::loadFromIni(ini::Configuration &configuration) {
    Entity::loadFromIni(configuration);
    m_speed = configuration["General"]["Speed"].as_double_or_die();
}

