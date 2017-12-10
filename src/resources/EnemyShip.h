//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_RESOURCES_ENEMYSHIP_H
#define GRADIUS_RESOURCES_ENEMYSHIP_H

#include "Entity.h"
#include "../models/EnemyShip.h"
#include "../controllers/EnemyShip.h"

namespace resources {
    class EnemyShip : public Entity{
    private:
        std::string m_bulletType;
    public:
        void loadFromIni(std::string path, ini::Configuration& configuration);

        model_ptr create(const std::pair<float, float> &position);
    };
}


#endif //GRADIUS_ENEMYSHIP_H
