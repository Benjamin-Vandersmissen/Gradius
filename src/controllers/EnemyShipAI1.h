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
        float m_desiredY = static_cast<float >(Transformation::top() + Transformation::height()*drand48());;
    public:
        void update() override;
    };
}


#endif //GRADIUS_ENEMYSHIPAI1_H
