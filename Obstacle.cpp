//
// Created by uauser on 11/23/17.
//

#include "Obstacle.h"
#include "PlayerShip.h"

void models::Obstacle::handleCollision(model_ptr entity) {
    if(entity){
        auto player = std::dynamic_pointer_cast<models::PlayerShip>(entity);
        if(player){
            player->dealDamage(1);
            markDeleted();
        }
    }
}

model_ptr resources::Obstacle::create(const std::pair<float, float> &position) {
    auto model = std::make_shared<models::Obstacle>();
    model->hitbox(m_hitbox);

    auto view = std::make_shared<views::Obstacle>();
    auto controller = std::make_shared<controllers::Obstacle>();
    finalizeCreation(view, model, controller, position);
    return model;
}
