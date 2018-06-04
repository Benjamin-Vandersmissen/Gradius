//
// Created by benji on 4/06/18.
//

#include "Bullet.h"
#include "Obstacle.h"
#include "BorderObstacle.h"

void models::Bullet::handleCollision(std::vector<model_ptr> entities) {
    for(model_ptr entity : entities) {
        if (entity) {
            if (auto obstacle = std::dynamic_pointer_cast<models::Obstacle>(entity)){
                markDeleted();
            }
            if (auto bullet = std::dynamic_pointer_cast<models::Bullet>(entity)){
                markDeleted();
            }
            if (auto borderObstacle = std::dynamic_pointer_cast<models::BorderObstacle>(entity)){
                markDeleted();
            }
        }
    }
}
