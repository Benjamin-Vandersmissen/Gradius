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
    if(m_currPositionChangeCooldown == 0){
        m_desiredY = static_cast<float >(Transformation::top() + Transformation::height()*drand48());
        m_currPositionChangeCooldown = m_maxPositionChangeCooldown;
    }
    else{
        m_currPositionChangeCooldown--;
    }
    if(std::abs(m_model->position().second - m_desiredY) < 0.000001){
        m_currentDirection = {-0.5,0};
    }
    else if(m_model->position().second < m_desiredY){
        auto ship = std::dynamic_pointer_cast<models::Ship>(m_model);
        if(ship){
            m_currentDirection = {-0.5,std::min(1.0, (m_desiredY-ship->position().second)/ship->speed())};
        }
    }
    else{
        auto ship = std::dynamic_pointer_cast<models::Ship>(m_model);
        if(ship) {
            m_currentDirection = {-0.5, std::max(-1.0, (m_desiredY - ship->position().second / ship->speed()))};
        }
    }
    notify();
    m_fired = false;
}
