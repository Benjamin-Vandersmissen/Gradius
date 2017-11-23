//
// Created by uauser on 11/23/17.
//

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

models::PlayerBullet *resources::PlayerBullet::create(const std::pair<float, float> &position) {
    auto model = new models::PlayerBullet;
    model->m_speed = m_speed;
    model->hitbox(m_hitbox);

    auto view = new views::PlayerBullet;
    auto controller = new controllers::PlayerBullet;
    finalizeCreation(view, model, controller, position);
    return model;
}

void resources::PlayerBullet::loadFromIni(std::string path, ini::Configuration &configuration) {
    Entity::loadFromIni(path, configuration);
    m_speed = configuration["General"]["Speed"].as_double_or_die();
}
