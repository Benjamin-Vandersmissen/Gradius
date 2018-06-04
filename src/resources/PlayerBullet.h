//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_RESOURCES_PLAYERBULLET_H
#define GRADIUS_RESOURCES_PLAYERBULLET_H

#include "Bullet.h"

#include "../models/PlayerBullet.h"
#include "../controllers/PlayerBullet.h"


namespace resources{
    class PlayerBullet : public Bullet{
    public:
        model_ptr create(const std::pair<float, float> &position) override;
    };
}

#endif //GRADIUS_RESOURCES_PLAYERBULLET_H
