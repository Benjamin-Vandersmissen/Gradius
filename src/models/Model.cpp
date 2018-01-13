//
// Created by uauser on 12/14/17.
//

#include <iostream>
#include "Model.h"
#include "ScrollingEntity.h"
#include "PlayerShip.h"

void models::Model::addView(std::shared_ptr<views::View> view) {
    m_view = view;
}

void models::Model::setController(std::shared_ptr<controllers::Controller> controller) {
    m_controller = controller;
    controller->addModel(shared_from_this());
}

void models::Model::update() {
    if(m_controller->tryPaused()){
        m_paused = !m_paused;
        notify();
    }
    if(m_controller->tryExit()){
        m_exit = true;
        notify();
    }
    if(gameState() == gameStates::Running){
        if(m_players.empty()){
            loadGameDoneMenu();
            m_gameState = gameStates::GameLost;
        }
        if(m_xPosition > m_level.length()){
            loadGameDoneMenu();
            m_gameState = gameStates::GameWon;
        }
        m_level.dynamicLoad(m_xPosition + Transformation::width() + 2 * m_level.speed(), m_xPosition);
        m_xPosition += m_level.speed();
    }
    if(m_controller->typedChar() != 0 && gameState() == gameStates::LoadLevelMenu){
        if(invalidLevel)
            invalidLevel = false;
        if(m_controller->typedChar() == '\b' && !m_tempLevel.empty()){
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
    m_level.loadLevel("../levels/"+m_levelName+".json");
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

void models::Model::loadLevelMenu() {
    m_menu = {{0, 1.0f, "Load Level", menuStates::TryLoadLevel, menuStates::BackToMainMenu, -1},
              {0, 2.0f, "Main Menu", menuStates::BackToMainMenu, -1, menuStates::TryLoadLevel}};
    m_menuState = menuStates::TryLoadLevel;
}

void models::Model::loadGameDoneMenu() {
    m_menu = {{0, 0.0f, "Restart", menuStates::NewGame, menuStates::BackToMainMenu, -1},
              {0, 1.0f, "Main Menu", menuStates::BackToMainMenu, menuStates::ExitGame, menuStates::NewGame},
              {0, 2.0f, "Exit Game", menuStates::ExitGame, -1, menuStates::BackToMainMenu}};
    m_menuState = menuStates::NewGame;
}

void models::Model::loadLevel() {
    m_level.initLevel();
    m_xPosition = 0;
    ScrollingEntity::scrollingSpeed = m_level.speed();
    m_level.dynamicLoad(Transformation::width(), m_xPosition);
    m_players.clear();
    for(model_ptr obj : models::list){
        if(std::dynamic_pointer_cast<models::PlayerShip>(obj)){
            m_players.push_back(obj);
        }
    }
}

void models::Model::saveTempLevel() {
    m_levelName = m_tempLevel;
    m_tempLevel = "";
    m_level.loadLevel("../levels/"+m_levelName+".json");
}

void models::Model::deleteMarkedEntities() {
    bool deletedItems = false;
    for(auto it = list.begin(); it != list.end(); ++it){
        if((*it)->deleted()){
            deletedItems = true;
            auto player = std::find(m_players.begin(), m_players.end(), *it);
            if(player != m_players.end()){
                m_players.erase(player);
            }
            it = list.erase(it);
        }
    }
    if(!deletedItems)
        return;
    for(auto it = views::list.begin(); it != views::list.end(); ++it){
        if((*it)->deleted()){
            it = views::list.erase(it);
        }
    }
    for(auto it = controllers::list.begin(); it != controllers::list.end(); ++it){
        if((*it)->deleted()){
            it = controllers::list.erase(it);
        }
    }
}
