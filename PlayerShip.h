//
// Created by benji on 22.11.17.
//

#ifndef GRADIUS_PLAYERSHIP_H
#define GRADIUS_PLAYERSHIP_H

#include "Entity.h"
#include "Animation.h"

namespace views {
    class PlayerShip : public Entity{
    public:
        void update();

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override ;
    };
}

namespace models{
    class Playership : public Entity{
    private:
        float m_speed = 0.15;
    public:
        void update();
    };
}

namespace controllers{
    class Playership : public Entity{
    private:
        std::pair<float, float> m_currentDirection;
    public:
        void update();

        const std::pair<float, float> &currentDirection() const;
    };
}


#endif //GRADIUS_PLAYERSHIP_H
