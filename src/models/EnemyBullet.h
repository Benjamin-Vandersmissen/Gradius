//
// Created by benji on 10.12.17.
//

#ifndef GRADIUS_MODELS_ENEMYBULLET_H
#define GRADIUS_MODELS_ENEMYBULLET_H


#include "../controllers/EnemyBullet.h"
#include "Bullet.h"

namespace resources{
    class EnemyBullet;
}

namespace models {
    class EnemyBullet : public Bullet{
    public:
        friend class resources::EnemyBullet;

        void update() override ;

        void handleCollision(std::vector<model_ptr> entities) override;
    };
}


#endif //GRADIUS_MODELS_ENEMYBULLET_H
