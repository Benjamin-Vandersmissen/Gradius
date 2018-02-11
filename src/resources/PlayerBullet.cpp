//
// Created by benji on 09.12.17.
//

#include "PlayerBullet.h"

model_ptr resources::PlayerBullet::create(const std::pair<float, float> &position) {
    auto model = std::make_shared<models::PlayerBullet>();
    model->m_speed = m_speed;
    m_firedSound.play();

    auto view = std::make_shared<views::Entity>();
    auto controller = std::make_shared<controllers::PlayerBullet>();
    finalizeCreation(view, model, controller, position);
    return model;
}

void resources::PlayerBullet::loadFromIni(const std::string &path, const ini::Configuration &configuration) {
    Entity::loadFromIni(path, configuration);
    m_speed = configuration["General"]["Speed"].as_double_or_die();
    m_firedSoundBuffer = std::make_shared<sf::SoundBuffer>();
    m_firedSoundBuffer->loadFromFile(path + configuration["General"]["FiredSound"].as_string_or_default("./sounds/ShotFired.wav"));
    m_firedSound.setBuffer(*m_firedSoundBuffer);
    m_firedSound.setVolume(50);//50% of volume
}