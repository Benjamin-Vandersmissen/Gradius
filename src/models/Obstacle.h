//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_MODELS_OBSTACLE_H
#define GRADIUS_MODELS_OBSTACLE_H

#include "ScrollingEntity.h"

#include "../resources/Obstacle.h"
#include "../models/PlayerShip.h"

namespace resources{
    class Obstacle;
}

namespace models {
    class Obstacle : public ScrollingEntity{
    public:
        friend class resources::Obstacle;

        virtual void handleCollision(model_ptr entity) override;
    };
}


#endif //GRADIUS_MODELS_OBSTACLE_H
