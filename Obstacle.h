//
// Created by benji on 15.11.17.
//

#ifndef GRADIUS_OBSTACLE_H
#define GRADIUS_OBSTACLE_H


#include "ScrollingEntity.h"
#include "EntityView.h"
#include "EntityResource.h"

namespace entities {
    class Obstacle : public ScrollingEntity{
    public:
        Obstacle(const std::pair<float, float> &position, const sf::FloatRect &hitbox, float speed);
    };
}

namespace resources {
    class Obstacle : public EntityResource{
    public :
        Obstacle();

        std::shared_ptr<entities::Entity> create(const std::pair<float, float>& position) override;
    };
}

namespace views {
    class Obstacle : public EntityView{
    public:
        friend class resources::Obstacle;

        explicit Obstacle(std::shared_ptr<entities::Entity> associatedEntity);
    };
}


#endif //GRADIUS_OBSTACLE_H
