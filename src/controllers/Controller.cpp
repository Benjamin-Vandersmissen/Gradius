//
// Created by uauser on 12/14/17.
//

#include "Controller.h"

void controllers::Controller::addModel(std::shared_ptr<models::Model> model) {
    m_model = model;
}
