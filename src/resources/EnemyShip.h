//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_RESOURCES_ENEMYSHIP_H
#define GRADIUS_RESOURCES_ENEMYSHIP_H

#include "Ship.h"
#include "../models/EnemyShip.h"
#include "../controllers/EnemyShip.h"
#include "Ship.h"

namespace resources {
    class EnemyShip : public Ship{
    private:
        int m_AI;
    public:
        void loadFromIni(const std::string &path, const ini::Configuration &configuration) override;

        model_ptr create(const std::pair<float, float> &position) override;
    };
}


#endif //GRADIUS_ENEMYSHIP_H
