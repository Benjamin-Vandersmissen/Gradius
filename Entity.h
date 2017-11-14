//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_ENTITY_H
#define GRADIUS_ENTITY_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

#include "Transformation.h"
#include <iostream>


namespace entities {
    class Entity : public sf::Drawable{
    protected:
        sf::Sprite* m_sprite;
        std::pair<float, float> m_position;
        std::pair<float, float> m_direction;
        float m_speed;
    public:
        /**
         * Check if two entities collide
         * */
        friend bool collides(Entity* entity1, Entity* entity2);

        static std::vector<entities::Entity*> entityList;

        Entity(const std::pair<float, float> &position, sf::Texture *texture, float speed);

        virtual void handleEvent(sf::Event& event){};

        virtual void update();

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        /**
         * Check if there is a collision
         * */
        Entity* checkCollision();

        /**
         * Executed on collision
         * */
        virtual void onCollision(Entity* entity){};

        /**
         * removes the entity from entityList and calls the destructor
         * */
        void destroy();
    };

    bool collides(Entity* entity1, Entity* entity2);
}


#endif //GRADIUS_ENTITY_H
