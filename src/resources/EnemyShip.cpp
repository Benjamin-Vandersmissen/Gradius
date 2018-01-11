//
// Created by benji on 09.12.17.
//

#include "EnemyShip.h"
#include "../controllers/EnemyShipAI1.h"
#include "../controllers/EnemyShipAI2.h"

void resources::EnemyShip::loadFromIni(const std::string &path, const ini::Configuration &configuration) {
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

    view_ptr view = (m_drawLives)?std::make_shared<views::Ship>(): std::make_shared<views::Entity>();
    if(m_drawLives) {
        std::dynamic_pointer_cast<views::Ship>(view)->m_heartTexture = m_heartTexture;
    }
    std::shared_ptr<controllers::EnemyShip> controller;
    switch(m_AI){
        case 0:
            controller = std::make_shared<controllers::EnemyShip>();
            break;
        case 1:
            controller = std::make_shared<controllers::EnemyShipAI1>();
            break;
        case 2:
            controller = std::make_shared<controllers::EnemyShipAI2>();
            break;
        default:
            controller = std::make_shared<controllers::EnemyShip>();
            break;
    }
    controller->m_maxFireCooldown = m_fireCooldown;
    finalizeCreation(view, model, controller, position);
    return model;
}