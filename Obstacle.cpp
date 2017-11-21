//
// Created by benji on 15.11.17.
//

#include "Obstacle.h"

entities::Obstacle::Obstacle(const std::pair<float, float> &position, const sf::FloatRect &hitbox, float speed)
        : ScrollingEntity(position, hitbox, speed) {}

views::Obstacle::Obstacle(std::shared_ptr<entities::Entity> associatedEntity) : EntityView(associatedEntity) {}

resources::Obstacle::Obstacle() = default;

std::shared_ptr<entities::Entity> resources::Obstacle::create(const std::pair<float, float> &position) {
    std::shared_ptr<entities::Obstacle> entity = std::make_shared<entities::Obstacle>(position, m_hitbox, m_speed);
    views::Obstacle* view = new views::Obstacle(entity);
    view->m_animation = m_animation;
    views::viewList.push_back(view);
    entities::entityList.push_back(entity);
    return entity;
}
