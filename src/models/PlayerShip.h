
//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_MODELS_PLAYERSHIP_H
#define GRADIUS_MODELS_PLAYERSHIP_H

#include "Entity.h"

#include "../controllers/PlayerShip.h"
#include "../resources/PlayerShip.h"

namespace resources{
    class PlayerShip;
}

void clamp(float& value, float lo, float hi);

namespace models{
    class PlayerShip : public Entity{
    private:
        double m_speed = 0.08;

        unsigned int m_maxLives = 3;

        unsigned int m_lives = m_maxLives;

        std::string m_bulletType = "";

        unsigned int m_maxImmunity = 60;

        unsigned int m_immunity = 0;
    public:
        friend class resources::PlayerShip;

        void update();

        void dealDamage(unsigned int damage);

        unsigned int lives() const;

        bool isImmune() const;

    };
}


#endif //GRADIUS_MODELS_PLAYERSHIP_H
