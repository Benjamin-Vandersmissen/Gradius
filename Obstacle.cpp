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

models::Obstacle *resources::Obstacle::create(const std::pair<float, float> &position) {
    auto model = new models::Obstacle;
    model->hitbox(m_hitbox);

    auto view = new views::Obstacle;
    auto controller = new controllers::Obstacle;
    finalizeCreation(view, model, controller, position);
    return model;
}
