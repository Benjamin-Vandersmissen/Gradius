//
// Created by benji on 10.12.17.
//

#include "Ship.h"
#include "../controllers/Ship.h"

void models::Ship::update() {
    if(isImmune()){
        m_immunity--;
    }
    auto myController = std::dynamic_pointer_cast<controllers::Ship>(m_controller);
    if(myController->fired()){
        try {
            auto bullet = resources::map.at(m_bulletType)->create(std::pair<float,float>{m_position.first + m_hitbox.bounds().width / 2, m_position.second + m_hitbox.bounds().height / 2});
            bullet->position(std::pair<float,float>{m_position.first, m_position.second + m_hitbox.bounds().height / 2});
        }catch(std::exception& e){
            throw ResourceException(ResourceException::missingResource, m_bulletType);
        }
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
    notify();
}

unsigned int models::Ship::lives() const {
    return m_lives;
}

bool models::Ship::isImmune() const {
    return m_immunity > 0;
}

