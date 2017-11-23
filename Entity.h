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
    };
    extern std::list<Entity*> list;
}

namespace views{
    class Entity : public sf::Drawable{
    protected:
        models::Entity* m_model;
    public:

        friend class resources::Entity;

        Animation m_animation = Animation(0);

        void setModel(models::Entity *model);

        virtual void update();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
            target.draw(m_animation, states);
        };
    };

    extern std::list<Entity*> list;
}

namespace controllers{
    class Entity{
    protected:
        models::Entity* m_model;

    public:
        void addModel(models::Entity* model);

        virtual void update() =0;

        void notify();

        virtual void handleEvent(const sf::Event& event){};
    };
    extern std::list<Entity*> list;
}

namespace resources{
    class Entity{
    protected:
        Animation m_animation;
    public:
        virtual models::Entity *create(const std::pair<float, float> &position) =0;

        virtual void loadFromIni(std::string path, ini::Configuration &configuration);

        void setAnimationOfView(views::Entity* view);
    };

    extern std::map<std::string, resources::Entity*> map;
}
#endif //GRADIUS_ENTITY_H
