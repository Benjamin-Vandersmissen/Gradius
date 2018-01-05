//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_MODELS_ENEMYSHIP_H
#define GRADIUS_MODELS_ENEMYSHIP_H

#include "ScrollingEntity.h"
#include "Ship.h"

#include "../resources/EnemyShip.h"
#include "../controllers/EnemyShip.h"
#include "../models/PlayerShip.h"

namespace resources{
    class EnemyShip;
}

namespace models {
    class EnemyShip : public Ship{
    public:
        friend class resources::EnemyShip;

        void handleCollision(std::vector<model_ptr> entity) override;

        void update() override;
    };
}


#endif //GRADIUS_MODELS_ENEMYSHIP_H
