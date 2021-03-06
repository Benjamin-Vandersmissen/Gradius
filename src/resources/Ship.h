//
// Created by benji on 10.12.17.
//

#ifndef GRADIUS_RESOURCES_SHIP_H
#define GRADIUS_RESOURCES_SHIP_H

#include "Entity.h"

namespace resources {
    class Ship : public Entity {
    protected:
        unsigned int m_maxLives;

        std::string m_bulletType;

        double m_speed;

        unsigned int m_maxImmunity;

        unsigned int m_fireCooldown;

        std::shared_ptr<sf::Texture> m_heartTexture;

        bool m_drawLives;

    public:
        void loadFromIni(const std::string &path, const ini::Configuration &configuration) override;
    };
}


#endif //GRADIUS_SHIP_H
