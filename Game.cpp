//
// Created by benji on 13.11.17.
//

#include <iostream>
#include "Game.h"
#include "PlayerShip.h"
#include "EnemyShip.h"

Game::Game(unsigned int width, unsigned int height) {
    m_stopWatch = StopWatch::getStopWatch();
    m_window = new sf::RenderWindow(sf::VideoMode(width, height), "Gradius");
    Transformation::initTransformation(width, height);
    m_updatedelay = 1000000/100;
    sf::Texture* texture = new sf::Texture;
    texture->loadFromFile("../NES - Gradius - Gradius.png", {0,100,32,16});
    sf::Texture* texture2 = new sf::Texture;
    texture2->loadFromFile("../NES - Gradius - Gradius.png", {487,10,13,13});
    entities::Entity::entityList = {new entities::PlayerShip({-3,0}, texture, 0.10), new entities::EnemyShip({5,0}, texture2, 0.10)};
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
    for(entities::Entity* entity : entities::Entity::entityList){
        target.draw(*entity, states);
    }
}
