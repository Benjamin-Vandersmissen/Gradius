//
// Created by benji on 09.12.17.
//

#include "Entity.h"

std::multiset<view_ptr, views::viewCmpt>views::list = {};

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

bool views::viewCmpt::operator()(const view_ptr &lhs, const view_ptr &rhs) {
    return lhs->m_model->depth() < rhs->m_model->depth();
}
