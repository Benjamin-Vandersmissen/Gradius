//
// Created by benji on 09.12.17.
//

#include "EnemyBullet.h"
#include "../controllers/HomingEntity.h"
#include "../views/HomingEntity.h"

model_ptr resources::EnemyBullet::create(const std::pair<float, float> &position) {
    auto model = std::make_shared<models::EnemyBullet>();
    model->m_speed = m_speed;
    m_firedSound.play();

    view_ptr view;
    controller_ptr  controller;
    if(m_type == "normal") {
        controller = std::make_shared<controllers::EnemyBullet>();
        view = std::make_shared<views::Entity>();
    }
    else if(m_type == "homing") {
        controller = std::make_shared<controllers::HomingEntity>();
        view = std::make_shared<views::HomingEntity>();
    }
    finalizeCreation(view, model, controller, position);
    return model;
}
