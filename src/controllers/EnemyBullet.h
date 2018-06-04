//
// Created by benji on 10.12.17.
//

#ifndef GRADIUS_CONTROLLERS_ENEMYBULLET_H
#define GRADIUS_CONTROLLERS_ENEMYBULLET_H

#include "Entity.h"

namespace controllers {
    class EnemyBullet : public Entity{
    public:
        void update() override {
            m_currentDirection = {-1,0};
            notify();
        };
    };
}


#endif //GRADIUS_CONTROLLERS_ENEMYBULLET_H
