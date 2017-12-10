//
// Created by benji on 10.12.17.
//

#include "EnemyShip.h"

bool controllers::EnemyShip::fired() const {
    return m_fired;
}

void controllers::EnemyShip::update() {
    ScrollingEntity::update();
    if(m_fireCooldown == 0){
        m_fired = true;
        m_fireCooldown = m_maxFireCooldown;
    }
    else{
        m_fireCooldown--;
    }

    notify();
    m_fired = false;
}

const std::pair<float, float> &controllers::EnemyShip::currentDirection() const {
    return m_currentDirection;
}
