//
// Created by benji on 22.11.17.
//

#include "Game.h"



Game::Game() {
    m_view = std::make_shared<views::View>(800,600,std::string("Gradius"));
    m_model = std::make_shared<models::Model>();
    m_controller = std::make_shared<controllers::Controller>();
    m_model->setController(m_controller);
    m_view->setModel(m_model);
    Transformation::initTransformation(200,150);
}

void Game::loop() {
    while(m_view->window()->isOpen()){
        if(m_stopwatch->getElapsedTime() > 1000000/60){
            m_stopwatch->reset();
        }
        else{
            continue;
        }
        handleEvents();
        if(m_model->paused())
            continue;
        m_controller->update();
        models::deleteMarkedEntities();
        m_view->draw();
    }
}

void Game::handleEvents() {
    sf::Event event;
    while(m_view->window()->pollEvent(event)){
        m_controller->handleEvent(event);
    }
}

