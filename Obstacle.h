//
// Created by uauser on 11/23/17.
//

#ifndef GRADIUS_OBSTACLE_H
#define GRADIUS_OBSTACLE_H

#include "ScrollingEntity.h"

namespace resources{
    class Obstacle;
}

namespace views {
    class Obstacle : public ScrollingEntity{

    };
}

namespace models {
    class Obstacle : public ScrollingEntity{
    public:
        friend class resources::Obstacle;

        virtual void handleCollision(model_ptr entity) override;
    };
}

namespace controllers {
    class Obstacle : public ScrollingEntity{

    };
}

namespace resources {
    class Obstacle : public Entity{
    public:
        virtual model_ptr create(const std::pair<float, float> &position) override;
    };
}

#endif //GRADIUS_OBSTACLE_H
