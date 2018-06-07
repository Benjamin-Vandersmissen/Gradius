//
// Created by benji on 10.12.17.
//

#include "Ship.h"

bool controllers::Ship::fired() {
    return m_fired;
}

void controllers::Ship::fire() {
    if(m_fireCooldown == 0){
        m_fired = true;
        m_fireCooldown = m_maxFireCooldown;
    }
}

void controllers::Ship::update() {
    if(m_fireCooldown > 0){
        m_fireCooldown--;
    }
    notify();
    m_fired = false;
}
