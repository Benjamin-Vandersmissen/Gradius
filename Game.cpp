//
// Created by benji on 22.11.17.
//

#include "Game.h"

Game::Game() {
    m_model = new models::Model;
    m_controller = std::make_shared<controllers::Controller>();
    m_view = std::make_shared<views::View>(400,300);

    m_controller->setModel(m_model);
    m_controller->setView(m_view);
    m_view->setModel(m_model);
}

void Game::loop() {
    bool loop = true;
    while(loop){
        loop = m_controller->update();
    }
}
