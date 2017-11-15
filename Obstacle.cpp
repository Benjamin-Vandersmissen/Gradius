//
// Created by benji on 15.11.17.
//

#include "Obstacle.h"

entities::Obstacle::Obstacle(const std::pair<float, float> &position, const sf::FloatRect &hitbox, float speed)
        : ScrollingEntity(position, hitbox, speed) {}

views::Obstacle::Obstacle(entities::Entity *associatedEntity) : EntityView(associatedEntity) {}
