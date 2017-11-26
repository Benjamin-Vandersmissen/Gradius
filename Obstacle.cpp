//
// Created by uauser on 11/23/17.
//

#include "Obstacle.h"
#include "PlayerShip.h"

void models::Obstacle::handleCollision(models::Entity *entity) {
    if(entity){
        auto player = dynamic_cast<models::PlayerShip*>(entity);
        if(player){
            player->dealDamage(1);
            markDeleted();
        }
    }
}
