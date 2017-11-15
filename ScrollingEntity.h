//
// Created by benji on 14.11.17.
//

#ifndef GRADIUS_SCROLLINGENTITY_H
#define GRADIUS_SCROLLINGENTITY_H

#include "Entity.h"

namespace entities {
    class ScrollingEntity : public Entity{
    public:
        ScrollingEntity(const std::pair<float, float> &position, const sf::FloatRect &hitbox, float speed);
    };

}

#endif //GRADIUS_SCROLLINGENTITY_H
