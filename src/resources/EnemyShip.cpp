//
// Created by benji on 09.12.17.
//

#include "EnemyShip.h"

void resources::EnemyShip::loadFromIni(std::string path, ini::Configuration &configuration) {
    Entity::loadFromIni(path, configuration);
    m_bulletType = configuration["EnemyShip"]["BulletType"].as_string_or_default("PlayerBullet");
}

model_ptr resources::EnemyShip::create(const std::pair<float, float> &position) {
    auto model = std::make_shared<models::EnemyShip>();
    model->hitbox(m_hitbox);
    model->m_bulletType = m_bulletType;

    auto view = std::make_shared<views::Entity>();
    auto controller = std::make_shared<controllers::EnemyShip>();
    finalizeCreation(view, model, controller, position);
    return model;
}