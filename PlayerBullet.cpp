//
// Created by benji on 13.11.17.
//

#include "PlayerBullet.h"

entities::PlayerBullet::PlayerBullet(const std::pair<float, float> &position, sf::Texture *texture, float speed)
        : Entity(position, texture, speed) {
    m_direction = {speed, 0};
}

