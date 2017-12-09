//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_CONTROLLERS_PLAYERSHIP_H
#define GRADIUS_CONTROLLERS_PLAYERSHIP_H

#include "Entity.h"


namespace controllers{
    class PlayerShip : public Entity{
    private:
        std::pair<float, float> m_currentDirection;

        unsigned int m_fireCooldown = 0;

        unsigned int m_maxFireCooldown = 20;

        bool m_fired = false;
    public:
        void update();

        const std::pair<float, float> &currentDirection() const;

        void handleEvent(const sf::Event& event);

        bool fired();
    };
}


#endif //GRADIUS_PLAYERSHIP_H
