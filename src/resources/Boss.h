//
// Created by benji on 3/06/18.
//

#ifndef GRADIUS_RESOURCES_BOSS_H
#define GRADIUS_RESOURCES_BOSS_H

#include "../models/Boss.h"
#include "../controllers/Boss.h"
#include "EnemyShip.h"
#include "../controllers/EnemyShip.h"

namespace resources {
    class Boss : public EnemyShip{
    public:
        model_ptr create(const std::pair<float, float>& position) override ;
    };

}


#endif //GRADIUS_BOSS_H
