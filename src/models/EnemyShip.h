//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_MODELS_ENEMYSHIP_H
#define GRADIUS_MODELS_ENEMYSHIP_H

#include "ScrollingEntity.h"

#include "../resources/EnemyShip.h"
#include "../models/PlayerShip.h"

namespace resources{
    class EnemyShip;
}

namespace models {
    class EnemyShip : public ScrollingEntity{
    public:
        friend class resources::EnemyShip;

        void handleCollision(model_ptr entity) override;
    };
}


#endif //GRADIUS_MODELS_ENEMYSHIP_H
