//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_PLAYERBULLET_H
#define GRADIUS_PLAYERBULLET_H

#include "Entity.h"

namespace entities {
    class PlayerBullet : public Entity {
    public:
        PlayerBullet(const std::pair<float, float> &position, sf::Texture *texture, float speed);
    };
}


#endif //GRADIUS_PLAYERBULLET_H
