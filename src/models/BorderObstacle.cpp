//
// Created by benji on 09.12.17.
//

#include "BorderObstacle.h"

void models::BorderObstacle::handleCollision(model_ptr entity) {
    if(entity){
        auto player = std::dynamic_pointer_cast<models::PlayerShip>(entity);
        if(player){
            player->dealDamage(2);
        }
    }
}