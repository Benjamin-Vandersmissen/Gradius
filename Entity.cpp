//
// Created by benji on 13.11.17.
//

#include "Entity.h"

std::vector<entities::Entity*> entities::Entity::entityList = {};

void entities::Entity::update() {
    m_position = {m_position.first + m_direction.first, m_position.second + m_direction.second};
    m_sprite->setPosition(Transformation::invTransform(m_position));
    onCollision(checkCollision());
}

entities::Entity::Entity(const std::pair<float, float> &position, sf::Texture *texture, float speed) : m_position(position), m_sprite(new sf::Sprite), m_speed(speed){
    m_sprite->setTexture(*texture);
    m_sprite->setPosition(Transformation::invTransform(m_position));
}

void entities::Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*m_sprite, states);
}

entities::Entity *entities::Entity::checkCollision() {
    for(Entity* entity : entityList){
        if(entity == this)
            continue;
        if(collides(entity, this))
            return entity;
    }
    return nullptr;
}

bool ::entities::collides(entities::Entity *entity1, entities::Entity *entity2) {
    return entity1->m_sprite->getGlobalBounds().intersects(entity2->m_sprite->getGlobalBounds());
}

void entities::Entity::markDeleted() {
    m_deleted = true;
}

std::pair<double, double> entities::Entity::getPosition() {
    return m_position;
}

std::pair<double, double> entities::Entity::getDirection() {
    return m_direction;
}

bool entities::Entity::deleted() {
    return m_deleted;
}

void entities::Entity::destroy() {
    entityList.erase(std::find(entityList.begin(), entityList.end(), this));
    delete this;
}
