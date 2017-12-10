//
// Created by benji on 10.12.17.
//

#include "Ship.h"

const std::pair<float, float> &controllers::Ship::currentDirection() const {
    return m_currentDirection;
}

bool controllers::Ship::fired() {
    return m_fired;
}
