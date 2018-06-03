//
// Created by benji on 3/06/18.
//

#ifndef GRADIUS_MODEL_BOSS_H
#define GRADIUS_MODEL_BOSS_H

#include "EnemyShip.h"
#include "../resources/Boss.h"

namespace resources{
    class Boss;
}

namespace models {
    class Boss : public EnemyShip {
    public:
        friend class resources::Boss;
    };
}

#endif //GRADIUS_BOSS_H
