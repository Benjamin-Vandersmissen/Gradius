//
// Created by benji on 4/06/18.
//

#ifndef GRADIUS_CONTROLLERS_HOMINGENTITY_H
#define GRADIUS_CONTROLLERS_HOMINGENTITY_H

#include "Entity.h"

namespace controllers {
    class HomingEntity : public virtual Entity{
    protected:
        model_ptr m_target = nullptr;

        unsigned int updateTreshold = 3;

        unsigned int clock = updateTreshold;

        unsigned int maxDegreeChange = 10;
    public:

        bool isHoming(){
            return m_target != nullptr;
        }

        const std::pair<float, float>& getHomingPosition() const;

        void setTarget(const model_ptr& target);

        void update() override;

        void updateDirection();

        float getHomingAngle() const;
    };
}


#endif //GRADIUS_HOMINGENTITY_H
