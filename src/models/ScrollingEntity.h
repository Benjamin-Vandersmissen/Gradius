//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_MODELS_SCROLLINGENTITY_H
#define GRADIUS_MODELS_SCROLLINGENTITY_H

#include "Entity.h"

#include "../controllers/ScrollingEntity.h"

namespace models {
    class ScrollingEntity : public Entity{
    public:
        static double scrollingSpeed;

        virtual void update() override;
    };
}


#endif //GRADIUS_MODELS_SCROLLINGENTITY_H
