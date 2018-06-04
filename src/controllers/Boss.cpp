//
// Created by benji on 3/06/18.
//

#include "Boss.h"

void controllers::Boss::update() {
    auto position = m_model->position();
    if (position.first > 1){
       enterBattlefield();
    }
    else{
        if(auto ship = std::dynamic_pointer_cast<models::Boss>(m_model)){
            if(ship->hasBossImmunity())
                ship->makeVulnerable();
        }
        m_currentDirection = {0,0};

        if(m_fireCooldown == 0){
            m_fired = true;
            m_fireCooldown = m_maxFireCooldown;
        }
        else{
            m_fireCooldown--;
        }
    }
    notify();
    m_fired = false;
}

void controllers::Boss::enterBattlefield() {
    m_currentDirection = {-0.1,0};
    auto ship = std::dynamic_pointer_cast<models::Boss>(m_model);
    if(ship)
        ship->makeImmmune();
}
