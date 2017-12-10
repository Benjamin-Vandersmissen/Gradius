
//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_MODELS_PLAYERSHIP_H
#define GRADIUS_MODELS_PLAYERSHIP_H

#include "Entity.h"

#include "Ship.h"
#include "../controllers/PlayerShip.h"
#include "../resources/PlayerShip.h"

namespace resources{
    class PlayerShip;
}

void clamp(float& value, float lo, float hi);

namespace models{
    class PlayerShip : public Ship{
    public:
        friend class resources::PlayerShip;

        void update();

    };
}


#endif //GRADIUS_MODELS_PLAYERSHIP_H
