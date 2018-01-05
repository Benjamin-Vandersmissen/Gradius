//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_MODELS_PLAYERBULLET_H
#define GRADIUS_MODELS_PLAYERBULLET_H


#include "Entity.h"

#include "../controllers/PlayerBullet.h"
#include "../resources/PlayerBullet.h"
#include "EnemyShip.h"
#include "EnemyBullet.h"

namespace resources{
    class PlayerBullet;
}

namespace models {
    class PlayerBullet : public Entity {
    private:
        double m_speed = 0.12;
    public:
        friend class resources::PlayerBullet;

        void update() override;

        void handleCollision(std::vector<model_ptr> entity) override;
    };
}


#endif //GRADIUS_MODELS_PLAYERBULLET_H
