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
    m_texture = new sf::Texture;
    m_texture->loadFromFile("../NES - Gradius - Gradius.png", {51,154,8,4});

    m_sprite.setTexture(*m_texture);
}
