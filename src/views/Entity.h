//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_VIEWS_ENTITY_H
#define GRADIUS_VIEWS_ENTITY_H

#include <memory>
#include <list>
#include <set>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "../Animation.h"
#include "../Transformation.h"

#include "../models/Entity.h"

namespace models{
    class Entity;
}

using model_ptr = std::shared_ptr<models::Entity>;

namespace views{
    class Entity;
}

namespace resources{
    class Entity;
}

using view_ptr = std::shared_ptr<views::Entity>;

namespace views{

    class Entity : public sf::Drawable, public std::enable_shared_from_this<views::Entity>{
    protected:
        model_ptr m_model; // the associated model

        bool m_deleted = false; //if the view is deleted or not

        Animation m_animation = Animation(0); //the default animation

    public:

        friend class resources::Entity;

        /**
         * @brief set the model to pull data from
         *
         * @param model the subject for Observer pattern
         * */
        void setModel(model_ptr model);

        /**
         * @brief update the internal state of the view
         * */
        virtual void update();

        /**
         * @brief inherited from sf::Drawable, makes it possible to draw a view directly to a SFML window
         * */
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
            target.draw(m_animation, states);
        };

        /**
         * @brief updates the internal counter of the animation and switches frame if necessary
         * */
        void updateAnimation();

        /**
         * @brief mark the view as deleted
         * */
        void markDeleted(){m_deleted = true;}

        /**
         * @brief returns wether the view is deleted or not
         * */
        bool deleted() const;

        friend struct viewCmpt;
    };

    struct viewCmpt{
        /**
         * comparator for two views, will return whether the left view has a lower depth or not
         * */
        bool operator()(const view_ptr &lhs, const view_ptr &rhs);
    };

    extern std::multiset<view_ptr, viewCmpt> list;
}


#endif //GRADIUS_VIEWS_ENTITY_H
