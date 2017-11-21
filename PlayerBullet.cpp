//
// Created by benji on 13.11.17.
//

#include "PlayerBullet.h"
#include "EnemyShip.h"

entities::PlayerBullet::PlayerBullet(const std::pair<float, float> &position, const sf::FloatRect &hitbox, float speed)
        : Entity(position, hitbox, speed) {
    m_direction = {speed,0};
}


void entities::PlayerBullet::onCollision(entities::Entity *entity) {
    EnemyShip* enemyShip = dynamic_cast<EnemyShip*>(entity);
    if(enemyShip){
        enemyShip->markDeleted();
        markDeleted();
    }

}

views::PlayerBullet::PlayerBullet(std::shared_ptr<entities::Entity> associatedEntity) : EntityView(associatedEntity) {
}

std::shared_ptr<entities::Entity> resources::PlayerBullet::create(const std::pair<float, float> &position) {
    std::shared_ptr<entities::PlayerBullet> entity = std::make_shared<entities::PlayerBullet>(position, m_hitbox, m_speed);

    views::PlayerBullet* view = new views::PlayerBullet(entity);
    view->m_animation = m_animation;
    views::viewList.push_back(view);
    entities::entityList.push_back(entity);
    return entity;
}

resources::PlayerBullet::PlayerBullet() = default;

resources::PlayerBullet::PlayerBullet(Animation animation, const sf::FloatRect &hitbox, float speed) : EntityResource(
        animation, hitbox, speed) {}
