//
// Created by uauser on 12/14/17.
//

#ifndef GRADIUS_MODEL_H
#define GRADIUS_MODEL_H

#include <memory>
#include "Entity.h"
#include "../views/View.h"
#include "../controllers/Controller.h"

namespace views{
    class View;
}

namespace controllers{
    class Controller;
}

namespace models {
    struct menuObject{
        float xPosition;
        float yPosition;
        std::string string;
        int menuState;
        int nextState;
        int prevState;
    };
    class Model : public std::enable_shared_from_this<models::Model>{
    private:
        std::shared_ptr<views::View> m_view;
        std::shared_ptr<controllers::Controller> m_controller;
        bool m_paused = false;
        bool m_exit = false;
        int m_gameState = gameStates::MainMenu;
        int m_menuState = menuStates::NewGame;
        std::vector<menuObject> m_menu;
    public:
        Model();

        enum gameStates{
            MainMenu,
            PauseMenu,
            Running
        };

        enum menuStates{
            NewGame,
            LoadLevel,
            ExitGame,
            ContinueGame
        };

        void addView(std::shared_ptr<views::View> view);

        void setController(std::shared_ptr<controllers::Controller> controller);

        void update();

        void notify();

        bool paused() const {return m_paused;}

        bool exit() const {return m_exit;}

        const int gameState() const {return m_gameState;}

        void setGameState(int state);

        menuObject currentMenuObject() const;

        const int menuState() const { return m_menuState;}

        void setMenuState(int state);

        const std::vector<menuObject>& getMenu() const;

        void loadMainMenu();

        void loadPauseMenu();
    };
}


#endif //GRADIUS_MODEL_H
