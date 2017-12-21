//
// Created by uauser on 12/14/17.
//

#include <iostream>
#include "Model.h"

void models::Model::addView(std::shared_ptr<views::View> view) {
    m_view = view;
}

void models::Model::setController(std::shared_ptr<controllers::Controller> controller) {
    m_controller = controller;
    controller->addModel(shared_from_this());
}

void models::Model::update() {
    if(m_controller->tryPaused()){
        m_paused = true;
        notify();
    }
    if(m_controller->tryExit()){
        m_exit = true;
        notify();
    }
    if(m_controller->typedChar() != 0){
        if(m_controller->typedChar() == '\b' && m_tempLevel.size() > 0){
            m_tempLevel.pop_back();
        }
        else if (m_controller->typedChar() != '\b'){
            m_tempLevel += m_controller->typedChar();
        }
        notify();
    }
}

void models::Model::notify() {
    m_view->update();
}

const std::vector<models::menuObject> &models::Model::getMenu() const {
    return m_menu;
}

models::Model::Model() {
    loadMainMenu();
}

void models::Model::setGameState(int state) {
    m_gameState = state;
}

models::menuObject models::Model::currentMenuObject() const {
    for(menuObject obj : m_menu){
        if(obj.menuState == m_menuState){
            return obj;
        }
    }
}

void models::Model::setMenuState(int state) {
    m_menuState = state;
}

void models::Model::loadMainMenu() {
    m_menu = {{0, -1.0f, "New Game", menuStates::NewGame, menuStates::LoadLevel, -1},
              {0, 0, "Load Level", menuStates::LoadLevel, menuStates::ExitGame, menuStates::NewGame},
              {0, 1.0f, "Exit Game", menuStates ::ExitGame, -1, menuStates::LoadLevel}};
    m_menuState = menuStates::NewGame;
}

void models::Model::loadPauseMenu() {
    m_menu = {{0, -1.0f, "Continue", menuStates::ContinueGame, menuStates::BackToMainMenu, -1},
              {0, 0, "Main Menu", menuStates::BackToMainMenu, menuStates::ExitGame, menuStates::ContinueGame},
              {0, 1.0f, "Quit", menuStates::ExitGame, -1, menuStates::BackToMainMenu}};
    m_menuState = menuStates::ContinueGame;
}
