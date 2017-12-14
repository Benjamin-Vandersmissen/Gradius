//
// Created by uauser on 12/14/17.
//

#include "View.h"

void views::View::setModel(std::shared_ptr<models::Model> model) {
    m_model = model;
    model->addView(shared_from_this());
    update();
}

void views::View::update() {

}
