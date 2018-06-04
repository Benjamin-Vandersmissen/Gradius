//
// Created by benji on 3/06/18.
//

#include "Boss.h"

void models::Boss::makeImmmune() {
    m_bossImmune = true;
    m_immunity = 2;
}

void models::Boss::update() {
    if (m_bossImmune)
        m_immunity = 2;
    EnemyShip::update();
}

void models::Boss::makeVulnerable() {
    m_bossImmune = false;
    m_immunity = 0;
}

bool models::Boss::hasBossImmunity() {
    return m_bossImmune;
}

void models::Boss::handleCollision(std::vector<model_ptr> entities) {
    for(model_ptr entity : entities) {
        if (entity) {
            auto player = std::dynamic_pointer_cast<models::PlayerShip>(entity);
            if (player) {
                player->dealDamage(2);
                dealDamage(1);
                return;
            }
        }
    }
}