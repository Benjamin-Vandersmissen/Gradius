//
// Created by benji on 15.11.17.
//

#ifndef GRADIUS_BORDEROBSTACLE_H
#define GRADIUS_BORDEROBSTACLE_H

#include "EntityView.h"
#include "Obstacle.h"

namespace entities {
    class BorderObstacle : public Obstacle{
    public:
        BorderObstacle(const std::pair<float, float> &position, const sf::FloatRect &hitbox, float speed);
    };
}

namespace views {
    class BorderObstacle : public EntityView{
    public:
        BorderObstacle(entities::Entity *associatedEntity);
    };
}

#endif //GRADIUS_BORDEROBSTACLE_H
