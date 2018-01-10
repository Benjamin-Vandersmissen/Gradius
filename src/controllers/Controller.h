//
// Created by uauser on 12/14/17.
//

#ifndef GRADIUS_CONTROLLER_H
#define GRADIUS_CONTROLLER_H

#include <memory>
#include "../models/Model.h"
#include "Entity.h"

namespace models{
    class Model;
}

namespace controllers{
    class Controller : public std::enable_shared_from_this<controllers::Controller>{
    private:
        std::shared_ptr<models::Model> m_model;
        bool m_tryPaused = false;
        bool m_tryExit = false;
        char m_typedChar;
    public:
        /**
         * @brief add a model for the MVC structure
         * */
        void addModel(std::shared_ptr<models::Model> model);

        /**
         * @brief notify the model of any changes
         * */
        void notify();

        /**
         * @brief handle events
         * */
        void handleEvent(const sf::Event &event);

        /**
         * @brief returns whether the controller tried to pause the game or not
         * */
        bool tryPaused() const {return m_tryPaused;}

        /**
         * @brief returns whether the controller tried to exit the game or not
         * */
        bool tryExit() const {return m_tryExit;}

        /**
         * @brief returns the last typed character
         * */
        char typedChar() const { return m_typedChar;}

        /**
         * @brief update the internal state
         * */
        void update();

        /**
         * @brief handle keyaboard input for a specific key
         * */
        void handleKeyboard(sf::Event::KeyEvent key);

        /**
         * @brief do something based on the current selected menu item
         * */
        void handleMenu();

    };
}


#endif //GRADIUS_CONTROLLER_H
