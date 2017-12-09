//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_RESOURCES_PLAYERBULLET_H
#define GRADIUS_RESOURCES_PLAYERBULLET_H

#include "Entity.h"

#include "../models/PlayerBullet.h"
#include "../controllers/PlayerBullet.h"

namespace resources{
    class PlayerBullet : public Entity{
    private:
        double m_speed;
    public:
        model_ptr create(const std::pair<float, float> &position);

        void loadFromIni(std::string path, ini::Configuration &configuration) override;
    };
}

#endif //GRADIUS_RESOURCES_PLAYERBULLET_H
