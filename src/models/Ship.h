//
// Created by benji on 10.12.17.
//

#ifndef GRADIUS_MODELS_SHIP_H
#define GRADIUS_MODELS_SHIP_H

#include "Entity.h"


namespace models {
    class Ship : public Entity{
    protected:
        double m_speed = 0.08;

        unsigned int m_maxLives = 3;

        unsigned int m_lives = m_maxLives;

        std::string m_bulletType = "";

        unsigned int m_maxImmunity = 60;

        unsigned int m_immunity = 0;

    public:
        void update();

        void dealDamage(unsigned int damage);

        unsigned int lives() const;

        bool isImmune() const;

        double speed() const;
    };
}


#endif //GRADIUS_MODELS_SHIP_H
