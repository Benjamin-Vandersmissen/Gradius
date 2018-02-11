//
// Created by benji on 09.12.17.
//

#include <iostream>
#include "ScrollingEntity.h"

double models::ScrollingEntity::scrollingSpeed = 0.05;

void models::ScrollingEntity::update() {
    if(m_position.first+m_hitbox.bounds().width < Transformation::left()) {
        markDeleted();
    }
}