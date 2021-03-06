//
// Created by benji on 10.12.17.
//

#ifndef GRADIUS_MODELS_SHIP_H
#define GRADIUS_MODELS_SHIP_H

#include "Entity.h"
#include "../resources/Ship.h"

namespace resources{
    class Ship;
}

namespace models {
    class Ship : public Entity{
    protected:
        double m_speed = 0.08;

        unsigned int m_maxLives = 3;

        unsigned int m_lives = m_maxLives;

        std::string m_bulletType = "";

        /**
         * @brief the maximum duration of immunity
         * */
        unsigned int m_maxImmunity = 60;

        /**
         * @brief the current duration of immunity
         * */
        unsigned int m_immunity = 0;

    public:
        void update() override;

        void dealDamage(unsigned int damage);

        unsigned int lives() const;

        bool isImmune() const;

    };
}


#endif //GRADIUS_MODELS_SHIP_H
