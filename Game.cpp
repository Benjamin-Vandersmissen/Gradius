//
// Created by benji on 22.11.17.
//

#include "Game.h"
#include "ScrollingEntity.h"


Game::Game() {
    m_window = new sf::RenderWindow(sf::VideoMode(200,150), "Gradius ~ Test");
    Transformation::initTransformation(200,150);
    models::Playership* model = new models::Playership;

    auto view = std::make_shared<views::PlayerShip>();
    auto controller = std::make_shared<controllers::Playership>();
    view->setModel(model);
    model->setController(controller);
    view->m_animation.createFromStrip("../resources/textures/PlayerShip_strip.png", 2);
    model->notify(); //synchronise the states
    m_models.push_back(model);
    m_controllers.push_back(controller);
    m_views.push_back(view);

    auto view2 = std::make_shared<views::ScrollingEntity>();
    auto controller2 = std::make_shared<controllers::ScrollingEntity>();
    models::ScrollingEntity* model2 = new models::ScrollingEntity;
    view2->setModel(model2);
    model2->setController(controller2);
    view2->m_animation.createFromStrip("../resources/textures/EnemyShip_strip.png", 3);
    model2->position(std::pair<float,float>{4,0});
    m_models.push_back(model2);
    m_controllers.push_back(controller2);
    m_views.push_back(view2);

}

void Game::loop() {
    while(!m_closed){
        if(m_stopwatch->getElapsedTime() > 1000000/60){
            m_stopwatch->reset();
        }
        else{
            continue;
        }
        handleEvents();
        for(auto controller : m_controllers){
            controller->update();
        }
        m_window->clear();
        for(auto view : m_views){
            m_window->draw(*view);
        }

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
