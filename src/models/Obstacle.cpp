//
// Created by benji on 09.12.17.
//

#include "Obstacle.h"

void models::Obstacle::handleCollision(std::vector<model_ptr> entities) {
    for(model_ptr entity : entities){
        if(entity){
            auto player = std::dynamic_pointer_cast<models::PlayerShip>(entity);
            if(player){
                player->dealDamage(1);
                markDeleted();
                return;
            }
        }
    }
}

void models::Obstacle::update() {
    auto controller = std::dynamic_pointer_cast<controllers::ScrollingEntity >(m_controller);
    if(controller){
        m_position.first += controller->scrollDirection().first*scrollingSpeed;
        m_position.second += controller->scrollDirection().second*scrollingSpeed;
        notify();
    }
    handleCollision(collision());
    ScrollingEntity::update();
}