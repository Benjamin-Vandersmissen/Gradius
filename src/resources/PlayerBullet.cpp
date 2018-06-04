//
// Created by benji on 09.12.17.
//

#include "PlayerBullet.h"

model_ptr resources::PlayerBullet::create(const std::pair<float, float> &position) {
    auto model = std::make_shared<models::PlayerBullet>();
    model->m_speed = m_speed;
    m_firedSound.play();

    auto view = std::make_shared<views::Entity>();
    auto controller = std::make_shared<controllers::PlayerBullet>();
    finalizeCreation(view, model, controller, position);
    return model;
}
