//
// Created by uauser on 11/28/17.
//

#ifndef GRADIUS_BORDEROBSTACLE_H
#define GRADIUS_BORDEROBSTACLE_H

#include "ScrollingEntity.h"

namespace resources{
    class BorderObstacle;
}

namespace views {
    class BorderObstacle : public ScrollingEntity {

    };
}

namespace models {
    class BorderObstacle : public ScrollingEntity {
    public:
        friend class resources::BorderObstacle;

        virtual void handleCollision(model_ptr entity) override;
    };
}

namespace controllers {
    class BorderObstacle : public ScrollingEntity {

    };
}

namespace resources {
    class BorderObstacle : public Entity {
        model_ptr create(const std::pair<float, float> &position);
    };
}


#endif //GRADIUS_BORDEROBSTACLE_H
