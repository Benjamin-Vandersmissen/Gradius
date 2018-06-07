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
    protected:
        bool m_bossImmune = true;
    public:
        friend class resources::Boss;

        void makeImmmune();

        void makeVulnerable();

        bool hasBossImmunity();

        void update() override;

        void handleCollision(std::vector<model_ptr> entities) override ;
    };
}

#endif //GRADIUS_BOSS_H
