//
// Created by benji on 15.11.17.
//

#include "BorderObstacle.h"

entities::BorderObstacle::BorderObstacle(const std::pair<float, float> &position, const sf::FloatRect &hitbox, float speed)
        : Obstacle(position, hitbox, speed) {}

views::BorderObstacle::BorderObstacle(std::shared_ptr<entities::Entity> associatedEntity) : EntityView(associatedEntity) {

}

resources::BorderObstacle::BorderObstacle() {}

std::shared_ptr<entities::Entity> resources::BorderObstacle::create(const std::pair<float, float> &position) {
    std::shared_ptr<entities::BorderObstacle> entity = std::make_shared<entities::BorderObstacle>(position, m_hitbox, m_speed);
    views::BorderObstacle* view = new views::BorderObstacle(entity);
    view->m_animation = m_animation;
    views::viewList.push_back(view);
    entities::entityList.push_back(entity);
    return entity;
}
