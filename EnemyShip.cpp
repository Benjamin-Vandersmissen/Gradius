//
// Created by benji on 23.11.17.
//

#include "EnemyShip.h"
#include "PlayerShip.h"

void models::EnemyShip::handleCollision(model_ptr entity) {
    if(entity){
        auto player = std::dynamic_pointer_cast<models::PlayerShip>(entity);
        if(player){
            player->dealDamage(1);
            markDeleted();
        }
    }
}

void resources::EnemyShip::loadFromIni(std::string path, ini::Configuration &configuration) {
    Entity::loadFromIni(path, configuration);
}

model_ptr resources::EnemyShip::create(const std::pair<float, float> &position) {
    auto model = std::make_shared<models::EnemyShip>();
    model->hitbox(m_hitbox);

    auto view = std::make_shared<views::EnemyShip>();
    auto controller = std::make_shared<controllers::EnemyShip>();
    finalizeCreation(view, model, controller, position);
    return model;
}
