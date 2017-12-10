//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_CONTROLLERS_PLAYERSHIP_H
#define GRADIUS_CONTROLLERS_PLAYERSHIP_H

#include "Ship.h"
#include "../resources/PlayerShip.h"

namespace resources{
    class PlayerShip;
}

namespace controllers{
    class PlayerShip : public Ship{
    public:
        friend class resources::PlayerShip;

        void update() override;

        void handleEvent(const sf::Event& event);
    };
}


#endif //GRADIUS_PLAYERSHIP_H
