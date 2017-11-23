//
// Created by benji on 23.11.17.
//

#include "EnemyShip.h"

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
