//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_RESOURCES_OBSTACLE_H
#define GRADIUS_RESOURCES_OBSTACLE_H

#include "Entity.h"

#include "../controllers/ScrollingEntity.h"
#include "../models/Obstacle.h"
#include "../models/ScrollingEntity.h"

namespace resources {
    class Obstacle : public Entity{
    public:
        model_ptr create(const std::pair<float, float> &position) override;
    };
}


#endif //GRADIUS_OBSTACLE_H
