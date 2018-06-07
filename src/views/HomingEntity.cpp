//
// Created by benji on 4/06/18.
//

#include "HomingEntity.h"

void views::HomingEntity::update() {
    Entity::update();
    auto controller = std::dynamic_pointer_cast<controllers::HomingEntity>(m_model->controller());
    m_animation.setRotation(-controller->getHomingAngle()-90);
}
