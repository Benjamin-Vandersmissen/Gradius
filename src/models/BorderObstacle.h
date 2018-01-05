//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_MODELS_BORDEROBSTACLE_H
#define GRADIUS_MODELS_BORDEROBSTACLE_H

#include "ScrollingEntity.h"

#include "../models/PlayerShip.h"
#include "../resources/BorderObstacle.h"

namespace resources{
    class BorderObstacle;
}

namespace models {
    class BorderObstacle : public ScrollingEntity {
    public:
        friend class resources::BorderObstacle;

        void handleCollision(std::vector<model_ptr> entity) override;

        void update() override ;
    };
}


#endif //GRADIUS_MODELS_BORDEROBSTACLE_H
