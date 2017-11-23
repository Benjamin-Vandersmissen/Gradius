//
// Created by benji on 22.11.17.
//

#include "Game.h"
#include "ScrollingEntity.h"


Game::Game() {
    m_window = new sf::RenderWindow(sf::VideoMode(200,150), "Gradius ~ Test");
    Transformation::initTransformation(200,150);
    models::Playership* model = new models::Playership;

    auto view = new views::PlayerShip();
    auto controller = new controllers::Playership();
    view->setModel(model);
    model->setController(controller);
    view->m_animation.createFromStrip("../resources/textures/PlayerShip_strip.png", 2);
    model->notify(); //synchronise the states
    models::list.push_back(model);
    controllers::list.push_back(controller);
    views::list.push_back(view);

    auto view2 = new views::ScrollingEntity();
    auto controller2 = new controllers::ScrollingEntity();
    models::ScrollingEntity* model2 = new models::ScrollingEntity;
    view2->setModel(model2);
    model2->setController(controller2);
    view2->m_animation.createFromStrip("../resources/textures/EnemyShip_strip.png", 3);
    model2->position(std::pair<float,float>{4,0});
    models::list.push_back(model2);
    controllers::list.push_back(controller2);
    views::list.push_back(view2);

}

void Game::loop() {
    while(m_window->isOpen()){
        if(m_paused){
            sf::Event event;
            while(m_window->pollEvent(event)){
                if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                    m_paused = !m_paused;
            }
            continue;
        }
        if(m_stopwatch->getElapsedTime() > 1000000/60){
            m_stopwatch->reset();
        }
        else{
            continue;
        }
        if(!m_window->hasFocus())
            continue;
        handleEvents();
        for(auto controller : controllers::list){
            controller->update();
        }
        m_window->clear();
        for(auto view : views::list){
            m_window->draw(*view);
        }
        m_window->display();
    }
}

void Game::handleEvents() {
    sf::Event event;
    while(m_window->pollEvent(event)){
        if(event.type == sf::Event::Closed)
            m_window->close();
        else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
            m_paused = !m_paused;
        }
        else{
            for (auto controller: controllers::list) {
                controller->handleEvent(event);
            }
        }
    }
}
