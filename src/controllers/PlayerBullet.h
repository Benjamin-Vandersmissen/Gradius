//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_CONTROLLERS_PLAYERBULLET_H
#define GRADIUS_CONTROLLERS_PLAYERBULLET_H

#include "Entity.h"

namespace controllers {
    class PlayerBullet : public Entity {
    private:

    public:

        void update() override {
            m_currentDirection = {1,0};
            notify();
        };
    };
}


#endif //GRADIUS_PLAYERBULLET_H
