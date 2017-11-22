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

bool controllers::Controller::update() {
    sf::Event event;
    sf::RenderWindow* window = m_view->window();
    while(window->pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:{
                window->close();
                return false;
            }
            default:{
                break;
            }
        }
    }
    m_view->update();
    return true;
}

void controllers::Controller::setView(const std::shared_ptr<views::View> &view) {
    m_view = view;
    std::cout << "View " << view << " set in Controller " << this << std::endl;
}
