//
// Created by uauser on 12/14/17.
//

#ifndef GRADIUS_MODEL_H
#define GRADIUS_MODEL_H

#include <memory>
#include "Entity.h"
#include "../views/View.h"
#include "../controllers/Controller.h"
#include "../Level.h"

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
        bool m_paused = true;
        bool m_exit = false;
        int m_gameState = gameStates::MainMenu;
        int m_menuState = menuStates::NewGame;
        std::vector<menuObject> m_menu;
        std::string m_tempLevel; //temporary levelname during level selection
        std::string m_levelName = "level";
        Level m_level = Level();
        float m_xPosition;
        std::vector<model_ptr> m_players;
        model_ptr m_boss;
    public:
        Model();

        enum gameStates{
            MainMenu,
            PauseMenu,
            LoadLevelMenu,
            Running,
            Bossfight,
            GameLost,
            GameWon
        };

        enum menuStates{
            NewGame,
            LoadLevel,
            ExitGame,
            ContinueGame,
            BackToMainMenu,
            TryLoadLevel
        };
        /**
         * @brief add the view for MVC structure
         * */
        void addView(std::shared_ptr<views::View> view);

        /**
         * @brief add the controller for MVC structure
         * */
        void setController(std::shared_ptr<controllers::Controller> controller);

        /**
         * @brief update the internal state
         * */
        void update();

        /**
         * @brief notify the view of any changes
         * */
        void notify();

        /**
         * @brief returns whether the game is paused or not
         * */
        bool paused() const {return m_paused;}

        /**
         * @brief returns whether the game is exited or not
         * */
        bool exit() const {return m_exit;}

        /**
         * @brief returns the current state of the game
         * */
        const int gameState() const {return m_gameState;}

        /**
         * @brief change the state of the game
         * */
        void setGameState(int state);

        /**
         * @brief returns the properties of the current selected menu item
         * */
        menuObject currentMenuObject() const;

        /**
         * @brief returns which menu item is currently selected
         * */
        const int menuState() const { return m_menuState;}

        /**
         * @brief change the current selected menu item
         * */
        void setMenuState(int state);

        /**
         * @brief returns the properties of all the items of the current menu
         * */
        const std::vector<menuObject>& getMenu() const;

        /**
         * @brief load the main menu
         * */
        void loadMainMenu();

        /**
         * @brief load the current menu
         * */
        void loadPauseMenu();

        /**
         * @brief load the level selection menu
         * */
        void loadLevelMenu();

        /**
         * @brief load the game over / game won menu
         * */
        void loadGameDoneMenu();

        /**
         * @brief returns the temporary level name
         * */
        const std::string& tempLevel() const {return m_tempLevel;}

        /**
         * @brief load the current level
         * */
        void loadLevel();

        /**
         * @brief change the selected level to the temporary level
         * */
        void saveTempLevel();

        /**
         * @brief delete entities that are marked for deletion
         * */
        void deleteMarkedEntities();

        /**
         * @brief if the loaded level is invalid, this value will be true
         * */
        bool invalidLevel = false;

        /**
         * @brief returns a value between 0 and 1, that is the amount of the level already completed
         * */
        float getProgress();

        /**
         * @brief dynamically loads new objects into the level and initializes them
         * */
        void dynamicLoadLevel();

        /**
         * @brief pauses the game
         * */
        void pause();

        /**
         * @brief unpauses the game
         * */
         void unpause();
    };
}


#endif //GRADIUS_MODEL_H
