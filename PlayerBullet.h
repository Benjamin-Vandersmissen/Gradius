//
// Created by uauser on 11/23/17.
//

#ifndef GRADIUS_PLAYERBULLET_H
#define GRADIUS_PLAYERBULLET_H

#include "Entity.h"

namespace views {
    class PlayerBullet : public Entity {

    };

}

namespace models {
    class PlayerBullet : public Entity {
    private:
        unsigned int m_speed;
    };
}

namespace controllers {
    class PlayerBullet : public Entity {
    private:
        std::pair<float, float> m_currentDirection;

    public:
        const std::pair<float, float>& currentDirection() const;
    };
}

#endif //GRADIUS_PLAYERBULLET_H
