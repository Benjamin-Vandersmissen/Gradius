//
// Created by benji on 09.12.17.
//

#include "BorderObstacle.h"

void models::BorderObstacle::handleCollision(std::vector<model_ptr> entities) {
    for(model_ptr entity : entities) {
        if (entity) {
            auto player = std::dynamic_pointer_cast<models::PlayerShip>(entity);
            if (player) {
                player->dealDamage(2);
            }
        }
    }
}

void models::BorderObstacle::update() {
    auto controller = std::dynamic_pointer_cast<controllers::ScrollingEntity >(m_controller);

    if(controller){
        m_position.first += controller->scrollDirection().first*scrollingSpeed;
        m_position.second += controller->scrollDirection().second*scrollingSpeed;
        if(m_position.first+m_hitbox.bounds().width < Transformation::left()){ //jump back to the other end of the screen
            float offset =  Transformation::width()/m_hitbox.bounds().width - static_cast<int>(Transformation::width()/m_hitbox.bounds().width);
            m_position.first = m_position.first+Transformation::width()+(offset+1)*m_hitbox.bounds().width ;
        }
        notify();
    }
}