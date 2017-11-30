//
// Created by uauser on 11/23/17.
//

#include "PlayerBullet.h"
#include "EnemyShip.h"

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
        if(m_position.first > Transformation::left()+Transformation::width())
            markDeleted();
        notify();
    }
    handleCollision(collision());
}

void models::PlayerBullet::handleCollision(model_ptr entity) {
    if(entity){
        auto ship = std::dynamic_pointer_cast<models::EnemyShip>(entity);
        if(ship){
            ship->markDeleted();
            markDeleted();
        }
    }
}

model_ptr resources::PlayerBullet::create(const std::pair<float, float> &position) {
    auto model = std::make_shared<models::PlayerBullet>();
    model->m_speed = m_speed;
    model->hitbox(m_hitbox);

    auto view = std::make_shared<views::PlayerBullet>();
    auto controller = std::make_shared<controllers::PlayerBullet>();
    finalizeCreation(view, model, controller, position);
    return model;
}

void resources::PlayerBullet::loadFromIni(std::string path, ini::Configuration &configuration) {
    Entity::loadFromIni(path, configuration);
    m_speed = configuration["General"]["Speed"].as_double_or_die();
}
