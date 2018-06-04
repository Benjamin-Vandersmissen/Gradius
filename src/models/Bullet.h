//
// Created by benji on 4/06/18.
//

#ifndef GRADIUS_MODELS_BULLET_H
#define GRADIUS_MODELS_BULLET_H

#include "Entity.h"

namespace models {
    class Bullet : public Entity{
    protected:
        double m_speed;
    public:
        void handleCollision(std::vector<model_ptr> entities) override;
    };
}


#endif //GRADIUS_BULLET_H
