//
// Created by benji on 13.11.17.
//

#include "PlayerBullet.h"
#include "EnemyShip.h"

entities::PlayerBullet::PlayerBullet(const std::pair<float, float> &position, sf::Texture *texture, float speed)
        : Entity(position, texture, speed) {
    m_direction = {speed, 0};
}


void entities::PlayerBullet::onCollision(entities::Entity *entity) {
    EnemyShip* enemyShip = dynamic_cast<EnemyShip*>(entity);
    if(enemyShip){
        enemyShip->destroy();
        std::cout << "A" << std::endl;
        destroy();
    }

}

