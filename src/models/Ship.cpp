//
// Created by benji on 10.12.17.
//

#include "Ship.h"

void models::Ship::update() {
    if(isImmune()){
        m_immunity--;
    }
}

void models::Ship::dealDamage(unsigned int damage) {
    if(isImmune()){
        return;
    }
    if(damage < m_lives){
        m_lives -= damage;
        m_immunity = m_maxImmunity;
    }
    else{
        m_lives = 0;
        markDeleted();
    }
}

unsigned int models::Ship::lives() const {
    return m_lives;
}

bool models::Ship::isImmune() const {
    return m_immunity > 0;
}
