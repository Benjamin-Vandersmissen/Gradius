//
// Created by benji on 14.11.17.
//

#ifndef GRADIUS_ENEMYSHIP_H
#define GRADIUS_ENEMYSHIP_H

#include "ScrollingEntity.h"

namespace entities {
    class EnemyShip : public  ScrollingEntity{
    public:
        EnemyShip(const std::pair<float, float> &position, sf::Texture *texture, float speed);
    };
}


#endif //GRADIUS_ENEMYSHIP_H
