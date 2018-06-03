//
// Created by benji on 09.12.17.
//

#include "PlayerShip.h"
#include "BorderObstacle.h"

void clamp(float &value, float lo, float hi) {
    if(value < lo){
        value = lo;
    }
    if(value > hi)
        value = hi;
}


void models::PlayerShip::update() {
    auto myController = std::dynamic_pointer_cast<controllers::PlayerShip>(m_controller);
    Ship::update();
    if(myController) {
        if(myController->currentDirection() != std::pair<float, float>{0,0}) {
            m_position.first += m_speed * myController->currentDirection().first;
            m_position.second += m_speed * myController->currentDirection().second;
            clamp(m_position.first,Transformation::left(), Transformation::left()+Transformation::width() - m_hitbox.bounds().width);
            clamp(m_position.second,Transformation::top(), Transformation::top()+Transformation::height() - m_hitbox.bounds().height);
            handleCollision(collision());
            notify();
        }
    }
}

void models::PlayerShip::handleCollision(std::vector<model_ptr> entities) {
    for(model_ptr entity : entities) {
        if (entity) {
            auto border = std::dynamic_pointer_cast<models::BorderObstacle>(entity);
            if (border) {
                dealDamage(2);
            }
        }
    }
}

