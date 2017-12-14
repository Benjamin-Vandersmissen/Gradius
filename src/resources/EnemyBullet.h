//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_RESOURCES_ENEMYBULLET_H
#define GRADIUS_RESOURCES_ENEMYBULLET_H

#include "Entity.h"

#include "../models/EnemyBullet.h"
#include "../controllers/EnemyBullet.h"

namespace resources{
    class EnemyBullet : public Entity{
    private:
        double m_speed;
    public:
        model_ptr create(const std::pair<float, float> &position) override;

        void loadFromIni(std::string path, ini::Configuration &configuration) override;
    };
}

#endif //GRADIUS_RESOURCES_ENEMYBULLET_H
