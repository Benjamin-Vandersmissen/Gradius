//
// Created by benji on 13.11.17.
//

#include <iostream>
#include "Game.h"
#include "PlayerShip.h"
#include "EnemyShip.h"
#include "BorderObstacle.h"

Game::Game(unsigned int width, unsigned int height) {
    m_stopWatch = StopWatch::getStopWatch();
    m_window = new sf::RenderWindow(sf::VideoMode(200, 150), "Gradius"); //the default size is 200x150, this will make it that everything is auto-scaled
    m_window->setSize({width,height});
    Transformation::initTransformation(200, 150);
    m_updatedelay = 1000000/100;
    sf::Texture* texture = new sf::Texture;
    texture->loadFromFile("../NES - Gradius - Gradius.png", {0,100,32,16});
    sf::Texture* texture2 = new sf::Texture;
    texture2->loadFromFile("../NES - Gradius - Gradius.png", {487,10,13,13});
    entities::Entity::entityList = {new entities::PlayerShip({-3,0}, {0,0,1.28,0.64}, 0.10), new entities::EnemyShip({5,0}, {0,0,0.52,0.52}, 0.10), new entities::BorderObstacle({4.25,-3}, {0,0,2.56,0.52}, 0.10)};
    views::EntityView::viewList = {new views::PlayerShip(entities::Entity::entityList[0]), new views::EnemyShip(entities::Entity::entityList[1]), new views::BorderObstacle(entities::Entity::entityList[2])};
}

Game::Game() : Game(400, 300) {

}

void Game::loop() {
    while(m_window->isOpen()) {
        if(!m_window->hasFocus() || m_stopWatch->getElapsedTime() < m_updatedelay)
            continue;
        else if(m_stopWatch->getElapsedTime() >= m_updatedelay) {
            m_stopWatch->reset();
        }
        sf::Event event;
        while(m_window->pollEvent(event)){
            if(handleEvent(event) == -1){ //returnvalue == -1 => window is closed
                return;
            }
        }
        m_window->clear();
        for(int i = 0; i < entities::Entity::entityList.size(); i++){
            entities::Entity* entity = entities::Entity::entityList[i];
            entity->update();
        }
        for(int i = 0; i < views::EntityView::viewList.size(); i++){
            views::EntityView* view = views::EntityView::viewList[i];
            view->update();
        }
        m_window->draw(*this);
        m_window->display();
    }
}

int Game::handleEvent(sf::Event &event) {
    switch(event.type){
        case sf::Event::Closed:
            m_window->close();
            return -1;
        default:
            for(int i = 0; i < entities::Entity::entityList.size(); i++){
                entities::Entity* entity = entities::Entity::entityList[i];
                entity->handleEvent(event);
            }
    }
    return 0;
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(views::EntityView* view : views::EntityView::viewList){
        target.draw(*view, states);
    }
}
