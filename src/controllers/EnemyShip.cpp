//
// Created by benji on 10.12.17.
//

#include "EnemyShip.h"

bool controllers::EnemyShip::fired() const {
    return m_fired;
}

void controllers::EnemyShip::update() {
    m_currentDirection = {-1,0};
    notify();
    m_fired = false;
}

