//
// Created by benji on 15.11.17.
//

#ifndef GRADIUS_OBSTACLE_H
#define GRADIUS_OBSTACLE_H


#include "ScrollingEntity.h"
#include "EntityView.h"

namespace entities {
    class Obstacle : public ScrollingEntity{
    public:
        Obstacle(const std::pair<float, float> &position, const sf::FloatRect &hitbox, float speed);
    };
}

namespace views {
    class Obstacle : public EntityView{
    public:
        Obstacle(entities::Entity *associatedEntity);
    };
}


#endif //GRADIUS_OBSTACLE_H
