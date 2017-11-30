//
// Created by uauser on 11/28/17.
//

#include "BorderObstacle.h"
#include "PlayerShip.h"

void models::BorderObstacle::handleCollision(model_ptr entity) {
    if(entity){
        auto player = std::dynamic_pointer_cast<models::PlayerShip>(entity);
        if(player){
            player->dealDamage(2);
        }
    }
}

model_ptr resources::BorderObstacle::create(const std::pair<float, float> &position) {
    auto model = std::make_shared<models::BorderObstacle>();
    model->hitbox(m_hitbox);

    auto view = std::make_shared<views::BorderObstacle>();
    auto controller = std::make_shared<controllers::BorderObstacle>();
    finalizeCreation(view, model, controller, position);
    return model;
}
