//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_ENTITY_H
#define GRADIUS_ENTITY_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

#include "Transformation.h"
#include <iostream>
#include <memory>


namespace entities {
    class Entity{
    protected:
        std::pair<float, float> m_position;
        std::pair<float, float> m_direction;
        float m_speed;
        bool m_deleted = false;
        sf::FloatRect m_hitbox;
    public:
        /**
         * Check if two entities collide
         * */
        friend bool collides(Entity* entity1, Entity* entity2);

        friend void deleteMarkedEntities();

        Entity(const std::pair<float, float> &position, const sf::FloatRect &hitbox, float speed);

        virtual void handleEvent(sf::Event& event){};

        virtual void update();

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
        void markDeleted();

        std::pair<float, float> getPosition();

        std::pair<float, float> getDirection();

        bool deleted();
    };

    bool collides(Entity* entity1, Entity* entity2);

    void deleteMarkedEntities();

    extern std::vector<std::shared_ptr<entities::Entity>> entityList;

}


#endif //GRADIUS_ENTITY_H
