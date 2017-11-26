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

namespace views{
    class Entity;
}

namespace controllers{
    class Entity;
}

namespace resources{
    class Entity;
}

namespace models {
    class Entity {
    protected:
        views::Entity* m_view;

        controllers::Entity* m_controller;

        std::pair<float, float> m_position;

        sf::FloatRect m_hitbox;

        bool m_deleted = false;
    public:
        void addView(views::Entity *view);

        void setController(controllers::Entity *controller);

        virtual void update() =0;

        void notify();

        const std::pair<float, float> &position() const;

        void position(const std::pair<float, float> &position);

        models::Entity* collision();

        virtual void handleCollision(models::Entity* entity){};

        sf::FloatRect globalHitbox();

        void hitbox(const sf::FloatRect hitbox);

        void markDeleted();

        bool deleted() const;
    };
    extern std::list<Entity*> list;

    void deleteMarkedEntities();
}

namespace views{
    class Entity : public sf::Drawable{
    protected:
        models::Entity* m_model;

        bool m_deleted = false;
    public:

        friend class resources::Entity;

        Animation m_animation = Animation(0);

        void setModel(models::Entity *model);

        virtual void update();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
            target.draw(m_animation, states);
        };

        void markDeleted(){m_deleted = true;}

        bool deleted() const;
    };

    extern std::list<Entity*> list;
}

namespace controllers{
    class Entity{
    protected:
        models::Entity* m_model;

        bool m_deleted = false;

    public:
        void addModel(models::Entity* model);

        virtual void update() =0;

        void notify();

        virtual void handleEvent(const sf::Event& event){};

        void markDeleted(){m_deleted = true;}

        bool deleted() const;
    };
    extern std::list<Entity*> list;
}

namespace resources{
    class Entity{
    protected:
        Animation m_animation;
        sf::FloatRect m_hitbox;
    public:
        virtual models::Entity *create(const std::pair<float, float> &position) =0;

        virtual void loadFromIni(std::string path, ini::Configuration &configuration);

        void setAnimationOfView(views::Entity* view);

        void finalizeCreation(views::Entity *view, models::Entity *model, controllers::Entity *controller,
                                      std::pair<float, float> position);
    };

    extern std::map<std::string, resources::Entity*> map;
}
#endif //GRADIUS_ENTITY_H
