//
// Created by benji on 4/06/18.
//

#ifndef GRADIUS_HOMINGENTITY_H
#define GRADIUS_HOMINGENTITY_H

#include "Entity.h"
#include "../controllers/HomingEntity.h"



namespace views {
    class HomingEntity : public Entity{
        void update() override;
    };
}


#endif //GRADIUS_HOMINGENTITY_H
