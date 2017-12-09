//
// Created by benji on 09.12.17.
//

#include "ScrollingEntity.h"

std::pair<float, float> controllers::ScrollingEntity::m_scrollDirection = {-1,0};

void controllers::ScrollingEntity::update() {
    if(m_scrollDirection != std::pair<float,float>{0,0})
        notify();
}

const std::pair<float, float> &controllers::ScrollingEntity::currentDirection() const {
    return m_scrollDirection;
}