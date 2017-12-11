//
// Created by benji on 09.12.17.
//

#include "EnemyShip.h"
#include "../controllers/EnemyShipAI1.h"

void resources::EnemyShip::loadFromIni(std::string path, ini::Configuration &configuration) {
    Ship::loadFromIni(path, configuration);
    m_AI = configuration["EnemyShip"]["AI"].as_int_or_default(0);
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
    std::shared_ptr<controllers::EnemyShip> controller;
    switch(m_AI){
        case 0:
            controller = std::make_shared<controllers::EnemyShip>();
            break;
        case 1:
            controller = std::make_shared<controllers::EnemyShipAI1>();
            break;
        default:
            controller = std::make_shared<controllers::EnemyShip>();
            break;
    }
    controller->m_maxFireCooldown = m_fireCooldown;
    finalizeCreation(view, model, controller, position);
    return model;
}