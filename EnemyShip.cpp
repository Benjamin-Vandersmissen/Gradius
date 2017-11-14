//
// Created by benji on 14.11.17.
//

#include "EnemyShip.h"

entities::EnemyShip::EnemyShip(const std::pair<float, float> &position, sf::Texture *texture, float speed)
        : ScrollingEntity(position, texture, speed) {}

views::EnemyShip::EnemyShip(entities::Entity *associatedEntity) : EntityView(associatedEntity) {
    m_texture = new sf::Texture;
    m_texture->loadFromFile("../NES - Gradius - Gradius.png", {487,10,13,13});
    m_sprite.setTexture(*m_texture);
}
