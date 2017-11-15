//
// Created by benji on 13.11.17.
//

#include "Entity.h"

std::vector<entities::Entity*> entities::Entity::entityList = {};

void entities::Entity::update() {
    m_position = {m_position.first + m_direction.first, m_position.second + m_direction.second};
    onCollision(checkCollision());
}

entities::Entity::Entity(const std::pair<float, float> &position, const sf::FloatRect &hitbox, float speed): m_position(position), m_hitbox(hitbox), m_speed(speed) {

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
    sf::FloatRect globalHitbox1 = {entity1->m_hitbox.left+entity1->m_position.first, entity1->m_hitbox.top+entity1->m_position.second, entity1->m_hitbox.width, entity1->m_hitbox.height};
    sf::FloatRect globalHitbox2 = {entity2->m_hitbox.left+entity2->m_position.first, entity2->m_hitbox.top+entity2->m_position.second, entity2->m_hitbox.width, entity2->m_hitbox.height};
    return globalHitbox1.intersects(globalHitbox2);
}

void entities::Entity::markDeleted() {
    m_deleted = true;
}

std::pair<float, float> entities::Entity::getPosition() {
    return m_position;
}

std::pair<float, float> entities::Entity::getDirection() {
    return m_direction;
}

bool entities::Entity::deleted() {
    return m_deleted;
}

void entities::Entity::destroy() {
    entityList.erase(std::find(entityList.begin(), entityList.end(), this));
    delete this;
}
