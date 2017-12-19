//
// Created by uauser on 12/14/17.
//

#include "Controller.h"

void controllers::Controller::addModel(std::shared_ptr<models::Model> model) {
    m_model = model;
}

void controllers::Controller::handleEvent(const sf::Event &event) {
    switch(event.type){
        case sf::Event::Closed:{
            m_tryExit = true;
            notify();
            m_tryExit = false;
            break;
        }
        case sf::Event::LostFocus:{
            m_tryPaused = true;
            notify();
            m_tryPaused = false;
            break;
        }
        case sf::Event::GainedFocus:{
            m_tryPaused = true;
            notify();
            m_tryPaused = false;
            break;
        }
        case sf::Event::KeyPressed:{
            if(event.key.code == sf::Keyboard::Escape){
                m_tryPaused = true;
                notify();
                m_tryPaused = false;
                break;
            }
            else if (!m_model->paused()){
                for(controller_ptr& controller : controllers::list){
                    controller->handleEvent(event);
                }
            }
            break;
        }
        default:{
            if(!m_model->paused()) {
                for (controller_ptr &controller : controllers::list) {
                    controller->handleEvent(event);
                }
            }
        }
    }
}

void controllers::Controller::notify() {
    m_model->update();
}
