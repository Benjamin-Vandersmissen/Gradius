//
// Created by benji on 10.12.17.
//

#include "EnemyBullet.h"

void models::EnemyBullet::update() {
    auto myController = std::dynamic_pointer_cast<controllers::EnemyBullet>(m_controller);
    if(myController){
        m_position = {m_position.first + m_speed*myController->currentDirection().first, m_position.second + m_speed*myController->currentDirection().second};
        if(m_position.first > Transformation::left()+Transformation::width())
            markDeleted();
        notify();
    }
    handleCollision(collision());
}

void models::EnemyBullet::handleCollision(model_ptr entity) {
    if(entity){
        auto ship = std::dynamic_pointer_cast<models::PlayerShip>(entity);
        if(ship){
            ship->dealDamage(1);
            markDeleted();
        }
    }
}
