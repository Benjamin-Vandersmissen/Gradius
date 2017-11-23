//
// Created by uauser on 11/23/17.
//

#ifndef GRADIUS_SCROLLINGENTITY_H
#define GRADIUS_SCROLLINGENTITY_H

#include "Entity.h"

namespace views {
    class ScrollingEntity : public Entity{

    };
}

namespace models {
    class ScrollingEntity : public Entity{
    public:
        static double scrollingSpeed;

        virtual void update() override;
    };
}

namespace controllers {
    class ScrollingEntity : public Entity{
    private:
        static std::pair<float, float> m_scrollDirection;
    public:
        virtual void update() override;

        const std::pair<float, float>& currentDirection() const;
    };
}


#endif //GRADIUS_SCROLLINGENTITY_H
