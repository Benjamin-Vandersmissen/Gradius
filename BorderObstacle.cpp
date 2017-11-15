//
// Created by benji on 15.11.17.
//

#include "BorderObstacle.h"

entities::BorderObstacle::BorderObstacle(const std::pair<float, float> &position, const sf::FloatRect &hitbox, float speed)
        : Obstacle(position, hitbox, speed) {}

views::BorderObstacle::BorderObstacle(entities::Entity *associatedEntity) : EntityView(associatedEntity) {
    m_texture = new sf::Texture();
    m_texture->loadFromFile("../NES - Gradius - Gradius.png", {8,383,64,13});
    m_sprite.setTexture(*m_texture);
}
