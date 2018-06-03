//
// Created by benji on 3/06/18.
//

#include "Boss.h"

model_ptr resources::Boss::create(const std::pair<float, float> &position) {
    auto model = std::make_shared<models::Boss>();
    auto controller = std::make_shared<controllers::Boss>();
    model->m_speed = m_speed;
    model->m_bulletType = m_bulletType;
    model->m_maxLives= m_maxLives;
    model->m_lives = m_maxLives;
    model->m_maxImmunity = m_maxImmunity;
    view_ptr view = (m_drawLives)?std::make_shared<views::Ship>(): std::make_shared<views::Entity>();
    if(m_drawLives) {
        std::dynamic_pointer_cast<views::Ship>(view)->m_heartTexture = m_heartTexture;
    }

    controller->m_maxFireCooldown = m_fireCooldown;
    finalizeCreation(view, model, controller, position);
    return model;
}
