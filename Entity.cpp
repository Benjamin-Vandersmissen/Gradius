//
// Created by benji on 22.11.17.
//

#include "Entity.h"

std::vector<models::Entity*> models::list = {};

std::vector<views::Entity*> views::list = {};

std::vector<controllers::Entity*> controllers::list = {};

void models::Entity::addView(views::Entity *view) {
    m_view = view;
}

void models::Entity::setController(controllers::Entity *controller) {
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

models::Entity *models::Entity::collision() {
    for(models::Entity* entity: models::list){
        if(entity->globalHitbox().intersects(this->globalHitbox()) && entity != this){
            return entity;
        }
    }
    return nullptr;
}

sf::FloatRect models::Entity::globalHitbox() {
    return {m_hitbox.left+m_position.first, m_hitbox.top+m_position.second, m_hitbox.width, m_hitbox.height};
}


void controllers::Entity::addModel(models::Entity *model) {
    m_model = model;
}

void controllers::Entity::notify() {
    m_model->update();
}

void views::Entity::setModel(models::Entity *model) {
    m_model = model;
    model->addView(this);
    model->notify();
}

void views::Entity::update() {
    m_animation.setPosition(Transformation::invTransform(m_model->position()));

}
