//
// Created by uauser on 11/23/17.
//

#include "ScrollingEntity.h"
double models::ScrollingEntity::scrollingSpeed = 0.05;

std::pair<float, float> controllers::ScrollingEntity::m_scrollDirection = {-1,0};

void models::ScrollingEntity::update() {
    auto controller = dynamic_cast<controllers::ScrollingEntity* >(m_controller);

    if(controller){
        m_position.first += controller->currentDirection().first*scrollingSpeed;
        m_position.second += controller->currentDirection().second*scrollingSpeed;
        if(m_position.first+m_hitbox.width < Transformation::left())
            markDeleted();
        notify();
    }
    handleCollision(collision());
}

void controllers::ScrollingEntity::update() {
    if(m_scrollDirection != std::pair<float,float>{0,0})
        notify();
}

const std::pair<float, float> &controllers::ScrollingEntity::currentDirection() const {
    return m_scrollDirection;
}
