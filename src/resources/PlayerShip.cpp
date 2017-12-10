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

    auto view = std::make_shared<views::PlayerShip>();
    view->m_font = m_font;
    view->initText();
    auto controller = std::make_shared<controllers::PlayerShip>();
    controller->m_maxFireCooldown = m_fireCooldown;
    finalizeCreation(view, model, controller, position);
    return model;
}

void resources::PlayerShip::loadFromIni(std::string path, ini::Configuration &configuration) {
    Ship::loadFromIni(path, configuration);

    std::string fontPath = path + configuration["PlayerShip"]["FontPath"].as_string_or_die();
    m_font = std::make_shared<sf::Font>();
    m_font->loadFromFile(fontPath);
}