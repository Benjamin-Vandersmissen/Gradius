//
// Created by benji on 14.11.17.
//

#include "ScrollingEntity.h"

entities::ScrollingEntity::ScrollingEntity(const std::pair<float, float> &position, sf::Texture *texture, float speed)
        : Entity(position, texture, speed) {
    m_direction = std::pair<double,double>(-speed, 0);
}

