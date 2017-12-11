//
// Created by benji on 09.12.17.
//

#include "EnemyShip.h"

void models::EnemyShip::handleCollision(model_ptr entity) {
    if(entity){
        auto player = std::dynamic_pointer_cast<models::PlayerShip>(entity);
        if(player){
            player->dealDamage(1);
            markDeleted();
        }
    }
}

void models::EnemyShip::update() {
    auto myController = std::dynamic_pointer_cast<controllers::EnemyShip>(m_controller);
    if(myController){
        if(myController->currentDirection() != std::pair<float, float>{0,0}) {
            m_position.first += m_speed * myController->currentDirection().first;
            m_position.second += m_speed * myController->currentDirection().second;
            notify();
        }

        if(myController->fired()){
            try {
                resources::map.at(m_bulletType)->create(
                        std::pair<float,float>{m_position.first + m_hitbox.width / 2, m_position.second + m_hitbox.height / 2});
            }catch(std::exception){
                throw ResourceException(ResourceException::missingResource, m_bulletType);
            }
        }
        handleCollision(collision());
    }
}