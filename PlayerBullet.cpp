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

models::PlayerBullet *resources::PlayerBullet::create() {
    auto model = new models::PlayerBullet;
    model->m_speed = m_speed;

    auto view = new views::PlayerBullet;
    auto controller = new controllers::PlayerBullet;
    model->setController(controller);
    view->setModel(model);

    models::list.push_back(model);
    views::list.push_back(view);
    controllers::list.push_back(controller);
    return model;
}

void resources::PlayerBullet::loadFromIni(ini::Configuration &configuration) {
    Entity::loadFromIni(configuration);
    m_speed = configuration["General"]["Speed"].as_double_or_die();
}
