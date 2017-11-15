//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_ENTITYRESOURCE_H
#define GRADIUS_ENTITYRESOURCE_H


#include "Entity.h"
#include "EntityView.h"

namespace resources {
    class EntityResource {
    public:
        virtual entities::Entity *create(const std::pair<float, float> &position) = 0;
    };
}


#endif //GRADIUS_ENTITYRESOURCE_H
