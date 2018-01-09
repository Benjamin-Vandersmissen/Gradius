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
            handleKeyboard(event.key);
            break;
        }
        case sf::Event::TextEntered:{
            if(m_model->gameState() == models::Model::LoadLevelMenu) {
                if (event.text.unicode < 128 && event.text.unicode != '\r') {
                    m_typedChar = static_cast<char>(event.text.unicode);
                    notify();
                    m_typedChar = 0;
                }
            }
            break;
        }
        default:{
            if(!m_model->paused() && m_model->gameState() != models::Model::MainMenu) {
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

void controllers::Controller::update() {
    if (m_model->gameState() == models::Model::Running) {
        for (const auto &controller : controllers::list) {
            controller->update();
        }
        m_model->update();
    }
    m_model->deleteMarkedEntities();
}

void controllers::Controller::handleKeyboard(sf::Event::KeyEvent key) {
    switch(m_model->gameState()){
        case models::Model::LoadLevelMenu:{
            switch (key.code){
                case sf::Keyboard::Return:{
                    handleMenu();
                    break;
                }
                case sf::Keyboard::Up :{
                    if(m_model->currentMenuObject().prevState != -1){
                        m_model->setMenuState(m_model->currentMenuObject().prevState);
                    }
                    break;
                }
                case sf::Keyboard::Down :{
                    if(m_model->currentMenuObject().nextState != -1){
                        m_model->setMenuState(m_model->currentMenuObject().nextState);
                    }
                    break;
                }
                case sf::Keyboard::Escape :{
                    m_model->setGameState(models::Model::MainMenu);
                    m_model->loadMainMenu();
                    break;
                }
                default:{
                    break;
                }
            }
            break;
        }
        case models::Model::PauseMenu:{
            //Does the same things as Main Menu except the Escape input => no break
            switch(key.code) {
                case sf::Keyboard::Escape : {
                    m_model->setGameState(models::Model::Running);
                }
            }
        }
        case models::Model::GameLost:{
            //does the same as models::Model::MainMenu
        }
        case models::Model::GameWon:{
            //does the same as models::Model::MainMenu
        }
        case models::Model::MainMenu:{
            switch (key.code){
                case sf::Keyboard::Return:{
                    handleMenu();
                    break;
                }
                case sf::Keyboard::Up :{
                    if(m_model->currentMenuObject().prevState != -1){
                        m_model->setMenuState(m_model->currentMenuObject().prevState);
                    }
                    break;
                }
                case sf::Keyboard::Down :{
                    if(m_model->currentMenuObject().nextState != -1){
                        m_model->setMenuState(m_model->currentMenuObject().nextState);
                    }
                    break;
                }
            }
            break;
        }
        case models::Model::Running:{
            switch (key.code){
                case sf::Keyboard::Escape :{
                    m_model->setGameState(models::Model::PauseMenu);
                    break;
                }
            }
        }

    }
}

void controllers::Controller::handleMenu() {
    switch(m_model->menuState()){
        case models::Model::NewGame : {
            m_model->setGameState(models::Model::Running);
            m_model->loadLevel();
            m_model->loadPauseMenu();
            break;
        }
        case models::Model::LoadLevel : {
            m_model->setGameState(models::Model::LoadLevelMenu);
            m_model->loadLevelMenu();
            break;
        }
        case models::Model::ExitGame : {
            m_tryExit = true;
            notify();
            break;
        }
        case models::Model::ContinueGame : {
            m_model->setGameState(models::Model::Running);
            break;
        }
        case models::Model::BackToMainMenu : {
            m_model->setGameState(models::Model::MainMenu);
            m_model->loadMainMenu();
            break;
        }
        case models::Model::TryLoadLevel : {
            m_model->saveTempLevel();
            m_model->setGameState(models::Model::MainMenu);
            m_model->loadMainMenu();
            break;
        }
    }
}
