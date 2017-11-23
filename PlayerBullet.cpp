//
// Created by uauser on 11/23/17.
//

#include <iostream>
#include "PlayerBullet.h"

const std::pair<float, float> &controllers::PlayerBullet::currentDirection() const {
    return m_currentDirection;
}

views::PlayerBullet::PlayerBullet() {
    m_animation.createFromStrip("../resources/textures/PlayerBullet.png", 1);
}

void models::PlayerBullet::update() {
    auto myController = dynamic_cast<controllers::PlayerBullet*>(m_controller);
    if(myController){
        m_position = {m_position.first + m_speed*myController->currentDirection().first, m_position.second + m_speed*myController->currentDirection().second};
        notify();
    }
}
