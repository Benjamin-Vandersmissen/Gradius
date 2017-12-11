//
// Created by benji on 11.12.17.
//

#ifndef GRADIUS_ENEMYSHIPAI1_H
#define GRADIUS_ENEMYSHIPAI1_H

#include "EnemyShip.h"
namespace controllers{
    class EnemyShipAI1 : public EnemyShip{
    private:
        unsigned int m_maxPositionChangeCooldown = 20;
        unsigned int m_currPositionChangeCooldown = 0;
        float m_desiredY = 0;
    public:
        void update();
    };
}


#endif //GRADIUS_ENEMYSHIPAI1_H
