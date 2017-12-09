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

    public:
        void addModel(model_ptr model);

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
         *
         * @return m_deleted
         * */
        bool deleted() const;
    };
    extern std::list<controller_ptr> list;
}


#endif //GRADIUS_CONTROLLERS_ENTITY_H
