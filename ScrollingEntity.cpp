//
// Created by benji on 14.11.17.
//

#include "ScrollingEntity.h"

entities::ScrollingEntity::ScrollingEntity(const std::pair<float, float> &position, const sf::FloatRect &hitbox,
                                           float speed)
        : Entity(position, hitbox, speed) {
    m_direction = {-speed, 0};
}
