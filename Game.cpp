//
// Created by benji on 13.11.17.
//

#include "Game.h"

Game::Game() {
    m_stopWatch = StopWatch::getStopWatch();
    m_window = new sf::RenderWindow(sf::VideoMode(1920,1080), "Gradius");
    m_updatedelay = 1000000/60; //60 fps
}

void Game::loop() {
    while(m_window->isOpen()) {
        if(!m_window->hasFocus() || m_stopWatch->getElapsedTime() < m_updatedelay)
            continue;
        else if(m_stopWatch->getElapsedTime() >= m_updatedelay)
            m_stopWatch->reset();

        sf::Event event;
        while(m_window->pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    m_window->close();
                    return;
                default:
                    break;
            }
        }
        m_window->clear();
        m_window->display();
    }
}
