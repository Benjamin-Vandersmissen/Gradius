//
// Created by benji on 09.12.17.
//

#include "EnemyShip.h"

void resources::EnemyShip::loadFromIni(std::string path, ini::Configuration &configuration) {
    Ship::loadFromIni(path, configuration);

}

model_ptr resources::EnemyShip::create(const std::pair<float, float> &position) {
    auto model = std::make_shared<models::EnemyShip>();
    model->m_speed = m_speed;
    model->m_bulletType = m_bulletType;
    model->m_maxLives= m_maxLives;
    model->m_lives = m_maxLives;
    model->m_maxImmunity = m_maxImmunity;
    model->hitbox(m_hitbox);

    auto view = std::make_shared<views::Entity>();
    auto controller = std::make_shared<controllers::EnemyShip>();
    controller->m_maxFireCooldown = m_fireCooldown;
    finalizeCreation(view, model, controller, position);
    return model;
}