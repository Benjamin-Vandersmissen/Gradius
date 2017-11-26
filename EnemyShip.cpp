//
// Created by benji on 23.11.17.
//

#include "EnemyShip.h"
#include "PlayerShip.h"

void models::EnemyShip::handleCollision(models::Entity *entity) {
    if(entity){
        auto player = dynamic_cast<models::PlayerShip*>(entity);
        if(player){
            player->dealDamage(1);
            markDeleted();
        }
    }
}

void resources::EnemyShip::loadFromIni(std::string path, ini::Configuration &configuration) {
    Entity::loadFromIni(path, configuration);
}

models::EnemyShip *resources::EnemyShip::create(const std::pair<float, float> &position) {
    auto model = new models::EnemyShip;
    model->hitbox(m_hitbox);

    auto view = new views::EnemyShip;
    auto controller = new controllers::EnemyShip;
    finalizeCreation(view, model, controller, position);
    return model;
}
