//
// Created by benji on 09.12.17.
//

#include "PlayerShip.h"

model_ptr resources::PlayerShip::create(const std::pair<float, float> &position) {
    auto model = std::make_shared<models::PlayerShip>();
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
    auto controller = std::make_shared<controllers::PlayerShip>();
    controller->m_maxFireCooldown = m_fireCooldown;
    finalizeCreation(view, model, controller, position);
    return model;
}

void resources::PlayerShip::loadFromIni(const std::string &path, const ini::Configuration &configuration) {
    Ship::loadFromIni(path, configuration);

    m_heartTexture = std::make_shared<sf::Texture>();
    m_heartTexture->loadFromFile("../resources/textures/heart.png");
}