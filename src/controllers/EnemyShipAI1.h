//
// Created by benji on 11.12.17.
//

#ifndef GRADIUS_ENEMYSHIPAI1_H
#define GRADIUS_ENEMYSHIPAI1_H

#include "EnemyShip.h"
namespace controllers{
    class EnemyShipAI1 : public EnemyShip{
    private:
        int m_direction = -1 + 2*(rand()%2);
        std::pair<float, float> m_startPosition;
        bool m_positionSet = false;
    public:
        void update() override;
    };
}


#endif //GRADIUS_ENEMYSHIPAI1_H
