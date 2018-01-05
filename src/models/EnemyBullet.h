//
// Created by benji on 10.12.17.
//

#ifndef GRADIUS_MODELS_ENEMYBULLET_H
#define GRADIUS_MODELS_ENEMYBULLET_H

#include "Entity.h"

#include "../controllers/EnemyBullet.h"
#include "PlayerShip.h"

namespace resources{
    class EnemyBullet;
}

namespace models {
    class EnemyBullet : public Entity{
    private:
        double m_speed = 0.12;
    public:
        friend class resources::EnemyBullet;

        void update() override ;

        void handleCollision(std::vector<model_ptr> entities) override;
    };
}


#endif //GRADIUS_MODELS_ENEMYBULLET_H
