//
// Created by benji on 09.12.17.
//

#include "Entity.h"

std::list<model_ptr> models::list = {};

void models::Entity::addView(view_ptr view) {
    m_view = view;
}

void models::Entity::setController(controller_ptr controller) {
    m_controller = controller;
    controller->addModel(shared_from_this());
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

std::vector<model_ptr> models::Entity::collision() {
    std::vector<model_ptr > entities;
    for(model_ptr entity: models::list){
        if(entity.get() != this && globalHitbox().intersects(entity->globalHitbox())){
            entities.push_back(entity);
        }
    }
    return entities;
}


void models::Entity::hitbox(const Hitbox &hitbox) {
    m_hitbox = hitbox;
}

bool models::Entity::deleted() const {
    return m_deleted;
}

void models::Entity::markDeleted() {
    m_deleted = true;
    m_view->markDeleted();
    m_controller->markDeleted();
}

int models::Entity::depth() const {
    return m_depth;
}

void models::Entity::depth(int depth) {
    m_depth = depth;
}

Hitbox models::Entity::globalHitbox() {
    return m_hitbox + sf::Vector2f{m_position.first, m_position.second};
}

controller_ptr models::Entity::controller() {
    return m_controller;
}
