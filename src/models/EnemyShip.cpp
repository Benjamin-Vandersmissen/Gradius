//
// Created by benji on 09.12.17.
//

#include "EnemyShip.h"

void models::EnemyShip::handleCollision(std::vector<model_ptr> entities) {
    for(model_ptr entity : entities) {
        if (entity) {
            auto player = std::dynamic_pointer_cast<models::PlayerShip>(entity);
            if (player) {
                player->dealDamage(1);
                dealDamage(1);
                return;
            }
        }
    }
}

void models::EnemyShip::update() {
    auto myController = std::dynamic_pointer_cast<controllers::EnemyShip>(m_controller);
    Ship::update();
    if(myController){
        m_position.first += m_speed * myController->currentDirection().first;
        m_position.second += m_speed * myController->currentDirection().second;
        notify();
        handleCollision(collision());
    }
    if(m_position.first+m_hitbox.bounds().width < Transformation::left()) {
        markDeleted();
    }
}