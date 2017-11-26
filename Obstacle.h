//
// Created by uauser on 11/23/17.
//

#ifndef GRADIUS_OBSTACLE_H
#define GRADIUS_OBSTACLE_H

#include "ScrollingEntity.h"

namespace resource{
    class Obstacle;
}

namespace views {
    class Obstacle : public ScrollingEntity{

    };
}

namespace models {
    class Obstacle : public ScrollingEntity{
    public:
        void handleCollision(models::Entity* entity) override;
    };
}

namespace controllers {
    class Obstacle : public ScrollingEntity{

    };
}

namespace resources {
    class Obstacle : public Entity{

    };
}

#endif //GRADIUS_OBSTACLE_H
