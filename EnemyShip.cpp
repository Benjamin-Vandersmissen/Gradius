//
// Created by benji on 14.11.17.
//

#include "EnemyShip.h"


entities::EnemyShip::EnemyShip(const std::pair<float, float> &position, const sf::FloatRect &hitbox, float speed)
        : ScrollingEntity(position, hitbox, speed) {}

views::EnemyShip::EnemyShip(entities::Entity *associatedEntity) : EntityView(associatedEntity) {

}

resources::EnemyShip::EnemyShip() {}

entities::EnemyShip *resources::EnemyShip::create(const std::pair<float, float> &position) {
    entities::EnemyShip* entity = new entities::EnemyShip(position, m_hitbox, m_speed);

    views::EnemyShip* view = new views::EnemyShip(entity);
    view->m_animation = m_animation;
    views::viewList.push_back(view);
    entities::entityList.push_back(entity);
    return entity;
}
