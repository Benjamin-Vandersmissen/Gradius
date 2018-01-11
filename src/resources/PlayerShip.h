//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_RESOURCES_PLAYERSHIP_H
#define GRADIUS_RESOURCES_PLAYERSHIP_H

#include "Ship.h"

#include "../models/PlayerShip.h"
#include "../views/Ship.h"
#include "../controllers/PlayerShip.h"

namespace resources {
    class PlayerShip : public Ship{
    private:
        std::shared_ptr<sf::Texture> m_heartTexture;
    public:
        void loadFromIni(const std::string &path, const ini::Configuration &configuration) override;

        model_ptr create(const std::pair<float, float> &position);
    };
}


#endif //GRADIUS_RESOURCES_PLAYERSHIP_H
