//
// Created by benji on 10.12.17.
//

#ifndef GRADIUS_CONTROLLERS_SHIP_H
#define GRADIUS_CONTROLLERS_SHIP_H

#include "Entity.h"

namespace controllers {
    class Ship : public Entity{
    protected:
        std::pair<float, float> m_currentDirection;

        unsigned int m_fireCooldown = 0;

        unsigned int m_maxFireCooldown = 20;

        bool m_fired = false;
    public:
        const std::pair<float, float> &currentDirection() const;

        bool fired();
    };
}


#endif //GRADIUS_SHIP_H