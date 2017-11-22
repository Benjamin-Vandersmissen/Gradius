//
// Created by benji on 22.11.17.
//

#ifndef GRADIUS_PLAYERSHIP_H
#define GRADIUS_PLAYERSHIP_H

#include "Entity.h"

namespace views {
    class PlayerShip : public Entity{
    public:
        void update();
    };
}

namespace models{
    class Playership : public Entity{
    private:
        unsigned int m_speed = 5;
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
