//
// Created by benji on 09.12.17.
//

#include "PlayerBullet.h"
#include "EnemyShip.h"


void models::PlayerBullet::update() {
    auto myController = std::dynamic_pointer_cast<controllers::PlayerBullet>(m_controller);
    if(myController){
        m_position = {m_position.first + m_speed*myController->currentDirection().first, m_position.second + m_speed*myController->currentDirection().second};
        if(m_position.first > Transformation::left()+Transformation::width())
            markDeleted();
        notify();
    }
    handleCollision(collision());
}

void models::PlayerBullet::handleCollision(std::vector<model_ptr> entities) {
    Bullet::handleCollision(entities);
    for(model_ptr entity : entities){
        if(entity){
            auto ship = std::dynamic_pointer_cast<models::EnemyShip>(entity);
            if(ship){
                ship->dealDamage(1);
                markDeleted();
                return;
            }
        }
    }
}