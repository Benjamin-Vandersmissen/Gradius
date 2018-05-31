
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

/**
 * @brief clamps a value between lo and hi
 * */
void clamp(float& value, float lo, float hi);

namespace models{
    class PlayerShip : public Ship{
    public:
        friend class resources::PlayerShip;

        void update() override ;

        void handleCollision(std::vector<model_ptr> entity) override ;
    };
}


#endif //GRADIUS_MODELS_PLAYERSHIP_H
