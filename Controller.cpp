//
// Created by benji on 22.11.17.
//

#include "Controller.h"

void controllers::Controller::setModel(models::Model *model){
    m_model = model;
    std::cout << "Model " << model << " set in Controller " << this << std::endl;
    m_model->setController(std::shared_ptr<controllers::Controller>(this));
}

void controllers::Controller::notify() {
    m_model->update();
}
