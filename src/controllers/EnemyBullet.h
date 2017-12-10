//
// Created by benji on 10.12.17.
//

#ifndef GRADIUS_CONTROLLERS_ENEMYBULLET_H
#define GRADIUS_CONTROLLERS_ENEMYBULLET_H

#include "Entity.h"

namespace controllers {
    class EnemyBullet : public Entity{
    protected:
        std::pair<float, float> m_currentDirection = {-1,0};

    public:
        const std::pair<float, float>& currentDirection() const;

        void update(){
            notify();
        };
    };
}


#endif //GRADIUS_CONTROLLERS_ENEMYBULLET_H
