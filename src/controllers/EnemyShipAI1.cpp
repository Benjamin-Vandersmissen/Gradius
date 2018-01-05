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
    auto ship = std::dynamic_pointer_cast<models::Ship>(m_model);
    if(std::abs(m_model->position().second - m_desiredY) < 0.000001){
        m_desiredY = static_cast<float >(Transformation::top() + Transformation::height()*drand48());
    }
    if(m_model->position().second < m_desiredY){
        if(ship){
            m_currentDirection = {-1,std::min(1.0, (m_desiredY-ship->position().second)/ship->speed())};
        }
    }
    else{
        if(ship) {
            m_currentDirection = {-1, std::max(-1.0, ((m_desiredY - ship->position().second)/ ship->speed()))};
        }
    }
    notify();
    if(m_model->collision().empty()){
        m_desiredY = static_cast<float >(Transformation::top() + Transformation::height()*drand48());
    }
    m_fired = false;
}
