//
// Created by benji on 09.12.17.
//

#include "PlayerBullet.h"

const std::pair<float, float> &controllers::PlayerBullet::currentDirection() const {
    return m_currentDirection;
}