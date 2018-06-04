//
// Created by benji on 10.12.17.
//

#ifndef GRADIUS_CONTROLLERS_SHIP_H
#define GRADIUS_CONTROLLERS_SHIP_H

#include "Entity.h"

namespace controllers {
    class Ship : public Entity{
    protected:

        unsigned int m_fireCooldown = 0; //the current cooldown before the ship can fire again

        unsigned int m_maxFireCooldown = 20; //the maximum cooldown before the ship can fire again

        bool m_fired = false;
    public:
        bool fired();
    };
}


#endif //GRADIUS_SHIP_H
