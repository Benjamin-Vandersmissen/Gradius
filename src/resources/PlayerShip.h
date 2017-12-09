//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_RESOURCES_PLAYERSHIP_H
#define GRADIUS_RESOURCES_PLAYERSHIP_H

#include "Entity.h"

#include "../models/PlayerShip.h"
#include "../views/PlayerShip.h"
#include "../controllers/PlayerShip.h"

namespace resources {
    class PlayerShip : public Entity{
    private:
        double m_speed;

        std::string m_bulletType;

        std::shared_ptr<sf::Font> m_font;

        unsigned int m_maxLives;
    public:
        void loadFromIni(std::string path, ini::Configuration &configuration) override;

        model_ptr create(const std::pair<float, float> &position);
    };
}


#endif //GRADIUS_RESOURCES_PLAYERSHIP_H
