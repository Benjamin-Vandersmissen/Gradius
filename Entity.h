//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_ENTITY_H
#define GRADIUS_ENTITY_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

namespace entities {
    class Entity : public sf::Drawable{
    protected:
        sf::Sprite* m_sprite;
        std::pair<float, float> m_position;
        std::pair<float, float> m_direction;
        float m_speed;
    public:
        Entity(const std::pair<float, float> &position, sf::Texture *texture, float speed);

        virtual void handleEvent(sf::Event& event){};

        virtual void update();

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}


#endif //GRADIUS_ENTITY_H
