//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_CONTROLLERS_PLAYERBULLET_H
#define GRADIUS_CONTROLLERS_PLAYERBULLET_H

#include "Entity.h"

namespace controllers {
    class PlayerBullet : public Entity {
    private:
        std::pair<float, float> m_currentDirection = {1,0};

    public:
        const std::pair<float, float>& currentDirection() const;

        void update() override {
            notify();
        };
    };
}


#endif //GRADIUS_PLAYERBULLET_H
