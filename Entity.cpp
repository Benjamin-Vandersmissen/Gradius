//
// Created by benji on 22.11.17.
//

#include "Entity.h"

void models::Entity::addView(std::shared_ptr<views::Entity> view) {
    m_view = view;
}

void models::Entity::setController(std::shared_ptr<controllers::Entity> controller) {
    m_controller = controller;
    controller->addModel(this);
}

void models::Entity::notify() {
    m_view->update();
}

const std::pair<float, float> &models::Entity::position() const {
    return m_position;
}

void models::Entity::position(const std::pair<float, float> &position) {
    m_position.first = position.first;
    m_position.second = position.second;
}

void controllers::Entity::addModel(models::Entity *model) {
    m_model = model;
}

void controllers::Entity::notify() {
    m_model->update();
}

void views::Entity::setModel(models::Entity *model) {
    m_model = model;
    model->addView(std::shared_ptr<views::Entity>(this));
}

void views::Entity::update() {
    m_animation.setPosition(Transformation::invTransform(m_model->position()));

}
