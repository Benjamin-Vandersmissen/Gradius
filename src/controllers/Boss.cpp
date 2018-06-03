//
// Created by benji on 3/06/18.
//

#include "Boss.h"

void controllers::Boss::update() {
    auto position = m_model->position();
    if (position.first > 1){
        m_currentDirection = {-1,0};
    }
    else{
        m_currentDirection = {0,0};
    }
    notify();
}