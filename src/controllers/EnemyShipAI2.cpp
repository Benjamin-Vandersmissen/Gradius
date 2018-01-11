//
// Created by benji on 11.01.18.
//

#include "EnemyShipAI2.h"

void controllers::EnemyShipAI2::update() {
    m_currentDirection = {-1,0};
    if(m_fireCooldown <= 0){
        m_fired = true;
        m_fireCooldown = m_maxFireCooldown;
    }
    else{
        m_fireCooldown--;
    }
    notify();
    m_fired = false;
}
