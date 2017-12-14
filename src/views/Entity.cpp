//
// Created by benji on 09.12.17.
//

#include "Entity.h"

std::list<view_ptr> views::list = {};

void views::Entity::setModel(model_ptr model) {
    m_model = model;
    model->addView(shared_from_this());
    update();
}

void views::Entity::update() {
    m_animation.setPosition(Transformation::invTransform(m_model->position()));

}

bool views::Entity::deleted() const {
    return m_deleted;
}

void views::Entity::updateAnimation() {
    m_animation.update();
}