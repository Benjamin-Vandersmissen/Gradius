//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_CONTROLLERS_ENTITY_H
#define GRADIUS_CONTROLLERS_ENTITY_H

#include <memory>
#include <list>

#include "../models/Entity.h"
#include "SFML/Graphics.hpp"

namespace models{
    class Entity;
}

using model_ptr = std::shared_ptr<models::Entity>;

namespace controllers{
    class Entity;
}

using controller_ptr = std::shared_ptr<controllers::Entity>;

namespace controllers{
    class Entity: public std::enable_shared_from_this<controllers::Entity>{
    protected:
        model_ptr m_model; //a pointer to the model

        bool m_deleted = false; //a boolean that will determine if the controller should be deleted

        std::pair<float, float> m_currentDirection = {-1, 0};
    public:
        /**
         * @brief add the model for the MVC structure
         * */
        void addModel(model_ptr model);

        /**
         * @brief update the internal state
         * */
        virtual void update() =0;

        /**
         * @brief notify all observers
         * */
        void notify();

        /**
         * @brief handle SFML events
         * */
        virtual void handleEvent(const sf::Event& event){};

        /**
         * @brief mark the controller for deletion
         * */
        void markDeleted(){m_deleted = true;}

        /**
         * @brief return if the controller is deleted
         * */
        bool deleted() const;

        /**
         * @brief returns the current direction
         * */
        const std::pair<float, float>& currentDirection();
    };
    extern std::list<controller_ptr> list; //a list that contains all active Entity Controllers
}


#endif //GRADIUS_CONTROLLERS_ENTITY_H
