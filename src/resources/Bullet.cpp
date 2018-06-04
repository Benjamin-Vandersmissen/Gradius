//
// Created by benji on 4/06/18.
//

#include "Bullet.h"

void resources::Bullet::loadFromIni(const std::string &path, const ini::Configuration &configuration) {
    Entity::loadFromIni(path, configuration);
    m_speed = configuration["General"]["Speed"].as_double_or_die();
    m_firedSoundBuffer = std::make_shared<sf::SoundBuffer>();
    m_firedSoundBuffer->loadFromFile(path + configuration["General"]["FiredSound"].as_string_or_default("./sounds/ShotFired.wav"));
    m_firedSound.setBuffer(*m_firedSoundBuffer);
    m_firedSound.setVolume(50);//50% of volume
}
