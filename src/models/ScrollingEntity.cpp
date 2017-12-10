//
// Created by benji on 09.12.17.
//

#include "ScrollingEntity.h"

double models::ScrollingEntity::scrollingSpeed = 0.05;

void models::ScrollingEntity::update() {
    auto controller = std::dynamic_pointer_cast<controllers::ScrollingEntity >(m_controller);

    if(controller){
        m_position.first += controller->scrollDirection().first*scrollingSpeed;
        m_position.second += controller->scrollDirection().second*scrollingSpeed;
        if(m_position.first+m_hitbox.width < Transformation::left())
            markDeleted();
        notify();
    }
    handleCollision(collision());
}