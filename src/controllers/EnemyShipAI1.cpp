//
// Created by benji on 11.12.17.
//

#include "EnemyShipAI1.h"

void controllers::EnemyShipAI1::update() {
    if(m_fireCooldown == 0){
        m_fired = true;
        m_fireCooldown = m_maxFireCooldown;
    }
    else{
        m_fireCooldown--;
    }
    if(!m_positionSet) {
        m_startPosition = m_model->position();
        m_positionSet = true;
    }
    if(m_direction*(m_model->position().second - m_startPosition.second - m_direction) > 0){ //reached desired position
        m_direction *= -1; //move other direction
    }
    m_currentDirection = {-1, 0.75*m_direction}; //vertical speed is 75% of horizontal speed => easier
    notify();
    m_fired = false;
}
