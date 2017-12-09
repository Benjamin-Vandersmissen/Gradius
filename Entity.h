//
// Created by benji on 22.11.17.
//

#ifndef GRADIUS_ENTITY_H
#define GRADIUS_ENTITY_H

#include <memory>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <iostream>
#include <fstream>
#include <list>
#include "Animation.h"
#include "Transformation.h"
#include "ini_configuration.hh"
#include "Exception.h"

namespace views{
    class Entity;
}

namespace controllers{
    class Entity;
}

namespace resources{
    class Entity;
}

namespace models{
    class Entity;
}

using view_ptr = std::shared_ptr<views::Entity>;
using model_ptr = std::shared_ptr<models::Entity>;
using controller_ptr = std::shared_ptr<controllers::Entity>;

namespace models {
    class Entity : public std::enable_shared_from_this<Entity>{
    protected:
        views::Entity* m_view;

        controller_ptr m_controller;

        std::pair<float, float> m_position;

        sf::FloatRect m_hitbox;

        bool m_deleted = false;
    public:
        void addView(views::Entity *view);

        void setController(controller_ptr controller);

        virtual void update() =0;

        void notify();

        const std::pair<float, float> &position() const;

        void position(const std::pair<float, float> &position);

        model_ptr collision();

        virtual void handleCollision(model_ptr entity){};

        sf::FloatRect globalHitbox();

        void hitbox(const sf::FloatRect hitbox);

        void markDeleted();

        bool deleted() const;
    };
    extern std::list<model_ptr> list;

    void deleteMarkedEntities();
}

namespace views{
    class Entity : public sf::Drawable, public std::enable_shared_from_this<Entity>{
    protected:
        model_ptr m_model;

        bool m_deleted = false;
    public:

        friend class resources::Entity;

        Animation m_animation = Animation(0);

        void setModel(model_ptr model);

        virtual void update();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
            target.draw(m_animation, states);
        };

        void updateAnimation();

        void markDeleted(){m_deleted = true;}

        bool deleted() const;
    };

    extern std::list<view_ptr > list;
}

namespace controllers{
    class Entity: public std::enable_shared_from_this<Entity>{
    protected:
        model_ptr m_model;

        bool m_deleted = false;

    public:
        void addModel(model_ptr model);

        virtual void update() =0;

        void notify();

        virtual void handleEvent(const sf::Event& event){};

        void markDeleted(){m_deleted = true;}

        bool deleted() const;
    };
    extern std::list<controller_ptr> list;
}

namespace resources{
    class Entity{
    protected:
        Animation m_animation;
        sf::FloatRect m_hitbox;
    public:
        virtual model_ptr create(const std::pair<float, float> &position) =0;

        virtual void loadFromIni(std::string path, ini::Configuration &configuration);

        void setAnimationOfView(view_ptr view);

        void finalizeCreation(view_ptr view, model_ptr model, controller_ptr controller,
                              std::pair<float, float> position);
    };

    extern std::map<std::string, resources::Entity*> map;
}
#endif //GRADIUS_ENTITY_H
