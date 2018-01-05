//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_RESOURCES_BORDEROBSTACLE_H
#define GRADIUS_RESOURCES_BORDEROBSTACLE_H

#include "Entity.h"

#include "../controllers/ScrollingEntity.h"
#include "../models/BorderObstacle.h"
#include "../models/ScrollingEntity.h"

namespace resources {
    class BorderObstacle : public Entity {
        model_ptr create(const std::pair<float, float> &position) override;
    };
}


#endif //GRADIUS_RESOURCES_BORDEROBSTACLE_H
