//
// Created by uauser on 11/28/17.
//

#include "BorderObstacle.h"
#include "PlayerShip.h"

void models::BorderObstacle::handleCollision(models::Entity *entity) {
    if(entity){
        auto player = dynamic_cast<models::PlayerShip*>(entity);
        if(player){
            player->dealDamage(2);
        }
    }
}

models::BorderObstacle *resources::BorderObstacle::create(const std::pair<float, float> &position) {
    auto model = new models::BorderObstacle;
    model->hitbox(m_hitbox);

    auto view = new views::BorderObstacle;
    auto controller = new controllers::BorderObstacle;
    finalizeCreation(view, model, controller, position);
    return model;
}
