//
// Created by uauser on 11/23/17.
//

#ifndef GRADIUS_PLAYERBULLET_H
#define GRADIUS_PLAYERBULLET_H

#include "Entity.h"

namespace views {
    class PlayerBullet : public Entity {
    public:
        PlayerBullet();

    };

}

namespace models {
    class PlayerBullet : public Entity {
    private:
        double m_speed = 0.12;
    public:
        void update();
    };
}

namespace controllers {
    class PlayerBullet : public Entity {
    private:
        std::pair<float, float> m_currentDirection = {1,0};

    public:
        const std::pair<float, float>& currentDirection() const;

        void update(){
            notify();
        };
    };
}

#endif //GRADIUS_PLAYERBULLET_H
