//
// Created by benji on 09.12.17.
//

#include "EnemyShip.h"

void resources::EnemyShip::loadFromIni(std::string path, ini::Configuration &configuration) {
    Entity::loadFromIni(path, configuration);
}

model_ptr resources::EnemyShip::create(const std::pair<float, float> &position) {
    auto model = std::make_shared<models::EnemyShip>();
    model->hitbox(m_hitbox);

    auto view = std::make_shared<views::Entity>();
    auto controller = std::make_shared<controllers::ScrollingEntity>();
    finalizeCreation(view, model, controller, position);
    return model;
}