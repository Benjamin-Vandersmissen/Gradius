//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_MODELS_ENTITY_H
#define GRADIUS_MODELS_ENTITY_H

#include <memory>
#include <list>

#include "../controllers/Entity.h"
#include "../views/Entity.h"
#include "../Hitbox.h"

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

        Hitbox m_hitbox = Hitbox(); //hitbox (coordinates)

        bool m_deleted = false; //if the model is deleted or not

        int m_depth = 0; //the depth at which the object gets drawn
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
        std::vector<model_ptr> collision();

        /**
         * @brief handle collision with a specific entity
         *
         * @param entity the colliding entity
         * */
        virtual void handleCollision(std::vector<model_ptr> entity){};

        /**
         * @brief returns the global hitbox (the hitbox + position)
         *
         * @return the global hitbox
         * */
        Hitbox globalHitbox();

        /**
         * @brief set the local hitbox
         *
         * @param hitbox the new hitbox
         * */
        void hitbox(const Hitbox &hitbox);

        /**
         * @brief mark this model as deleted
         * */
        void markDeleted();

        /**
         * @brief returns whether the model is deleted or not
         *
         * @return m_deleted
         * */
        bool deleted() const;

        /**
         * @brief returns the depth at which the instance is drawn
         * */
        int depth() const;

        /**
         * @brief sets the depth of the instance
         * */
        void depth(int depth);

        /**
         * @brief gets the controller
         * */
         controller_ptr controller();
    };
    extern std::list<model_ptr> list; //a list that holds all currently active Entity Models

}


#endif //GRADIUS_MODELS_ENTITY_H
