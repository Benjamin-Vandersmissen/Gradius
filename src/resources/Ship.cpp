//
// Created by benji on 10.12.17.
//

#include "Ship.h"

void resources::Ship::loadFromIni(const std::string &path, const ini::Configuration &configuration) {
    Entity::loadFromIni(path, configuration);

    m_speed = configuration["General"]["Speed"].as_double_or_die();
    m_bulletType = configuration["Ship"]["BulletType"].as_string_or_default("PlayerBullet");
    m_maxLives = configuration["Ship"]["Lives"].as_unsigned_or_default(3);
    m_fireCooldown = configuration["Ship"]["FireCooldown"].as_unsigned_or_default(20);
    m_maxImmunity = configuration["Ship"]["ImmunityDuration"].as_unsigned_or_default(60);
    m_drawLives = configuration["Ship"]["DrawLives"].as_bool_or_default(true);
    m_heartTexture = std::make_shared<sf::Texture>();
    m_heartTexture->loadFromFile("../resources/textures/heart.png");
}
