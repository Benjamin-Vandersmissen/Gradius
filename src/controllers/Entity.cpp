//
// Created by benji on 09.12.17.
//

#include "Entity.h"
std::list<controller_ptr> controllers::list = {};

void controllers::Entity::addModel(model_ptr model) {
    m_model = model;
}

void controllers::Entity::notify() {
    m_model->update();
}

bool controllers::Entity::deleted() const {
    return m_deleted;
}