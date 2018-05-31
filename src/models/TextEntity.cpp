//
// Created by benji on 31/05/18.
//

#include "TextEntity.h"

void models::TextEntity::update() {
    auto controller = std::dynamic_pointer_cast<controllers::ScrollingEntity >(m_controller);
    if(controller){
        m_position.first += controller->scrollDirection().first*scrollingSpeed;
        m_position.second += controller->scrollDirection().second*scrollingSpeed;
        notify();
    }
    ScrollingEntity::update();
}