//
// Created by benji on 10.12.17.
//

#ifndef GRADIUS_ENEMYSHIP_H
#define GRADIUS_ENEMYSHIP_H

#include "Ship.h"
#include "../resources/EnemyShip.h"
namespace resources{
    class EnemyShip;
}
namespace controllers {
    class EnemyShip : public Ship {
    public:
        friend class resources::EnemyShip;

        bool fired() const;

        void update();
    };
}


#endif //GRADIUS_ENEMYSHIP_H
