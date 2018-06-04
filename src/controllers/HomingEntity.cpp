//
// Created by benji on 4/06/18.
//

#include <iostream>
#include <cmath>
#include "HomingEntity.h"

const std::pair<float, float> &controllers::HomingEntity::getHomingPosition() const{
    return m_target->position();
}

void controllers::HomingEntity::setTarget(const model_ptr &target) {
    m_target = target;
}

void controllers::HomingEntity::update() {
    if(isHoming()){
        if(m_target->deleted()){
            m_target = nullptr;
        }
        else{
            clock++;
            if (clock > updateTreshold) {
                updateDirection();
                clock = 0;
            }
        }
    }
    notify();
}

void controllers::HomingEntity::updateDirection() {
    auto position = m_model->position();
    auto homingPosition = m_target->position();

    auto dx = homingPosition.first - position.first;
    auto dy = homingPosition.second - position.second;

    auto angle = std::atan2(dx,dy);
    auto currentAngle = std::atan2(m_currentDirection.first, m_currentDirection.second);

    auto x_component = std::sin(angle);
    auto y_component = std::cos(angle);

    auto difference = int((angle - currentAngle)*180/3.1415926) % 360;

    if(std::abs(difference) > maxDegreeChange){
        int sign = 0;
        if(difference > 0)
            sign = 1;
        else
            sign = -1;
        angle = currentAngle +maxDegreeChange*sign*3.1415926/180;
        x_component = std::sin(angle);
        y_component = std::cos(angle);
    }

    m_currentDirection = {x_component, y_component};
}

float controllers::HomingEntity::getHomingAngle() const {
    return 180*std::atan2(m_currentDirection.first, m_currentDirection.second)/3.1415926;
}
