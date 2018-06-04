//
// Created by benji on 3/06/18.
//

#ifndef GRADIUS_CONTROLLER_BOSS_H
#define GRADIUS_CONTROLLER_BOSS_H

#include "EnemyShip.h"
#include "../resources/Boss.h"

namespace resources{
    class Boss;
}

namespace controllers {
    class Boss : public EnemyShip{
    public:
        friend class resources::Boss;

        void update() override;

        void enterBattlefield();
    };
}


#endif //GRADIUS_BOSS_H
