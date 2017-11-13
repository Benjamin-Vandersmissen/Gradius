//
// Created by benji on 13.11.17.
//

#include "Entity.h"

void entities::Entity::update() {
    m_position = {m_position.first + m_direction.first, m_position.second + m_direction.second};
    m_sprite->setPosition(m_position.first, m_position.second);
}

entities::Entity::Entity(const std::pair<float, float> &position, sf::Texture *texture, float speed) : m_position(position), m_sprite(new sf::Sprite), m_speed(speed){
    m_sprite->setTexture(*texture);
    m_sprite->setPosition(position.first, position.second);
}

void entities::Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*m_sprite, states);
}
