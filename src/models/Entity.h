//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_MODELS_ENTITY_H
#define GRADIUS_MODELS_ENTITY_H

#include <memory>
#include <list>

#include "../controllers/Entity.h"
#include "../views/Entity.h"

namespace models{
    class Entity;
}

using model_ptr = std::shared_ptr<models::Entity>;

namespace views{
    class Entity;
}

using view_ptr = std::shared_ptr<views::Entity>;

namespace controllers{
    class Entity;
}

using controller_ptr = std::shared_ptr<controllers::Entity>;

namespace models {
    class Entity : public std::enable_shared_from_this<models::Entity>{
    protected:
        view_ptr m_view; //associated view

        controller_ptr m_controller; //associated controller

        std::pair<float, float> m_position; //current position (coordinates)

        sf::FloatRect m_hitbox; //hitbox (coordinates)

        bool m_deleted = false; //if the model is deleted or not
    public:

        /**
         * @brief add a view as observer
         *
         * @param view the view to add
         * */
        void addView(view_ptr view);

        /**
         * @brief add a controller to pull data from
         *
         * @param controller the controller to add
         * */
        void setController(controller_ptr controller);

        /**
         * @brief update the internal state
         * */
        virtual void update() =0;

        /**
         * @brief notify the observer
         * */
        void notify();

        /**
         * @brief get the current position
         *
         * @return m_position
         * */
        const std::pair<float, float> &position() const;


        /**
         * @brief set a new position
         *
         * @param position the new position
         * */
        void position(const std::pair<float, float> &position);

        /**
         * @brief detect the first model on the same position
         *
         * @return the model colliding with this model or null_ptr if none is found
         * */
        model_ptr collision();

        /**
         * @brief handle collision with a specific entity
         *
         * @param entity the colliding entity
         * */
        virtual void handleCollision(model_ptr entity){};

        /**
         * @brief returns the global hitbox (the hitbox + position)
         *
         * @return the global hitbox
         * */
        sf::FloatRect globalHitbox();

        /**
         * @brief set the local hitbox
         *
         * @param hitbox the new hitbox
         * */
        void hitbox(const sf::FloatRect hitbox);

        /**
         * @brief mark this model as deleted
         * */
        void markDeleted();

        /**
         * @brief returns wether the model is deleted or not
         *
         * @return m_deleted
         * */
        bool deleted() const;
    };
    extern std::list<model_ptr> list;

    /**
     * @brief delete all models for which Entity::deleted() returns true
     * */
    void deleteMarkedEntities();
}


#endif //GRADIUS_MODELS_ENTITY_H