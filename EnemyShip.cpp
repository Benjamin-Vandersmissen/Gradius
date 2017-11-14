//
// Created by benji on 14.11.17.
//

#include "EnemyShip.h"

entities::EnemyShip::EnemyShip(const std::pair<float, float> &position, sf::Texture *texture, float speed)
        : ScrollingEntity(position, texture, speed) {}
