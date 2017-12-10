//
// Created by benji on 10.12.17.
//

#ifndef GRADIUS_ENEMYSHIP_H
#define GRADIUS_ENEMYSHIP_H

#include "ScrollingEntity.h"

namespace controllers {
    class EnemyShip : public ScrollingEntity {
    protected:
        std::pair<float, float> m_currentDirection = {1,0};

        unsigned int m_fireCooldown = 0;

        unsigned int m_maxFireCooldown = 50;

        bool m_fired = false;

    public:
        bool fired() const;

        void update();

        const std::pair<float, float>& currentDirection() const;
    };
}


#endif //GRADIUS_ENEMYSHIP_H
