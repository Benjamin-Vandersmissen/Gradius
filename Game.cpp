//
// Created by benji on 13.11.17.
//

#include <iostream>
#include "Game.h"
#include "PlayerShip.h"

Game::Game() {
    m_stopWatch = StopWatch::getStopWatch();
    m_window = new sf::RenderWindow(sf::VideoMode(200,200), "Gradius");
    m_updatedelay = 1000000/60;
    sf::Texture* texture = new sf::Texture;
    texture->loadFromFile("../NES - Gradius - Gradius.png", {0,100,32,16});
    m_entities = {new entities::PlayerShip({20,20}, texture, 2)};
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
        for(entities::Entity* entity : m_entities){
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
            for(entities::Entity* entity : m_entities){
                entity->handleEvent(event);
            }
    }
    return 0;
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(entities::Entity* entity : m_entities){
        target.draw(*entity, states);
    }
}
