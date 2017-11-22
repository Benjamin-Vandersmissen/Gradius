//
// Created by benji on 22.11.17.
//

#include "Game.h"
#include "PlayerShip.h"

Game::Game() {
    m_window = new sf::RenderWindow(sf::VideoMode(400,300), "Gradius ~ Test");
    models::Playership* model = new models::Playership;
    auto view = std::make_shared<views::PlayerShip>();
    auto controller = std::make_shared<controllers::Playership>();
    view->setModel(model);
    model->setController(controller);
    m_models.push_back(model);
    m_controllers.push_back(controller);
    m_views.push_back(view);
}

void Game::loop() {
    while(!m_closed){
        handleEvents();
        for(auto controller : m_controllers){
            controller->update();
        }
        m_window->clear();
        m_window->display();
    }
}

void Game::handleEvents() {
    sf::Event event;
    while(m_window->pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:{
                m_closed = true;
            }
            default:{
                for(std::shared_ptr<controllers::Entity>& controller: m_controllers){
                    controller->handleEvent(event);
                }
            }
        }
    }
}
