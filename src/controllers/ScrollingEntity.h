//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_CONTROLLERS_SCROLLINGENTITY_H
#define GRADIUS_CONTROLLERS_SCROLLINGENTITY_H

#include "Entity.h"

namespace controllers {
    class ScrollingEntity : public Entity{
    public:
        static std::pair<float, float> m_scrollDirection;

        virtual void update() override;

        const std::pair<float, float>& scrollDirection() const;
    };
}


#endif //GRADIUS_CONTROLLERS_SCROLLINGENTITY_H
