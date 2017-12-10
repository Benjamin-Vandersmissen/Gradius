//
// Created by benji on 10.12.17.
//

#include "EnemyShip.h"

bool controllers::EnemyShip::fired() const {
    return m_fired;
}

void controllers::EnemyShip::update() {
    if(m_fireCooldown == 0){
        m_fired = true;
        m_fireCooldown = m_maxFireCooldown;
    }
    else{
        m_fireCooldown--;
    }

    m_currentDirection = {-1,0};

    notify();
    m_fired = false;
}

