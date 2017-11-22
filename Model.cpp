//
// Created by benji on 22.11.17.
//

#include "Model.h"

void models::Model::notify() {
    for(const std::shared_ptr<views::View>& view : m_views){
        view->update();
    }
}

void models::Model::update() {
}

void models::Model::setController(const std::shared_ptr<controllers::Controller>& controller) {
    m_controller = controller;
    std::cout << "Controller " << controller << " set in Model " << this << std::endl;
}

void models::Model::addView(std::shared_ptr<views::View> view) {
    m_views.insert(view);
    std::cout << "View " << view << " added in Model " << this << std::endl;
}
