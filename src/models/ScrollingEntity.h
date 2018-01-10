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
        static double scrollingSpeed; //the speed at which the window scrolls

        void update() override;
    };
}


#endif //GRADIUS_MODELS_SCROLLINGENTITY_H
