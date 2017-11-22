//
// Created by benji on 22.11.17.
//

#include "View.h"

void views::View::update() {

}

void views::View::setModel(models::Model *model) {
    m_model = model;
    std::cout << "Model " << model << " set in View " << this << std::endl;
    model->addView(std::shared_ptr<views::View>(this));
}
