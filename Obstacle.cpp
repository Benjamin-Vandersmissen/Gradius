//
// Created by benji on 15.11.17.
//

#include "Obstacle.h"

entities::Obstacle::Obstacle(const std::pair<float, float> &position, const sf::FloatRect &hitbox, float speed)
        : ScrollingEntity(position, hitbox, speed) {}

views::Obstacle::Obstacle(entities::Entity *associatedEntity) : EntityView(associatedEntity) {}

resources::Obstacle::Obstacle() {}

entities::Obstacle *resources::Obstacle::create(const std::pair<float, float> &position) {
    entities::Obstacle* entity = new entities::Obstacle(position, m_hitbox, m_speed);
    views::Obstacle* view = new views::Obstacle(entity);
    view->m_texture = m_texture;
    view->loadSprite();
    views::EntityView::viewList.push_back(view);
    entities::Entity::entityList.push_back(entity);
    return entity;
}
