//
// Created by uauser on 12/14/17.
//

#include "Model.h"

void models::Model::addView(std::shared_ptr<views::View> view) {
    m_view = view;
}

void models::Model::setController(std::shared_ptr<controllers::Controller> controller) {
    m_controller = controller;
    controller->addModel(shared_from_this());
}

void models::Model::update() {
    if(m_controller->tryPaused()){
        m_paused = true;
        notify();
    }
    if(m_controller->tryExit()){
        m_exit = true;
        notify();
    }
}

void models::Model::notify() {
    m_view->update();
}
