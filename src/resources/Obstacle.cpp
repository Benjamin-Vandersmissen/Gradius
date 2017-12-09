//
// Created by benji on 09.12.17.
//

#include "Obstacle.h"

model_ptr resources::Obstacle::create(const std::pair<float, float> &position) {
    auto model = std::make_shared<models::Obstacle>();
    model->hitbox(m_hitbox);

    auto view = std::make_shared<views::Entity>();
    auto controller = std::make_shared<controllers::ScrollingEntity>();
    finalizeCreation(view, model, controller, position);
    return model;
}