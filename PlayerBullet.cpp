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

views::PlayerBullet::PlayerBullet(entities::Entity *associatedEntity) : EntityView(associatedEntity) {
}

resources::PlayerBullet::PlayerBullet(sf::Texture *m_texture, float m_speed, const sf::FloatRect &m_hitbox)
        : m_texture(m_texture), m_speed(m_speed), m_hitbox(m_hitbox) {}

entities::PlayerBullet *resources::PlayerBullet::create(const std::pair<float, float> &position) {
    entities::PlayerBullet* entity = new entities::PlayerBullet(position, m_hitbox, m_speed);

    views::PlayerBullet* view = new views::PlayerBullet(entity);
    view->m_texture = m_texture;
    view->loadSprite();
    views::EntityView::viewList.push_back(view);
    entities::Entity::entityList.push_back(entity);
    return entity;
}
