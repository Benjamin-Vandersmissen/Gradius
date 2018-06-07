//
// Created by benji on 7/06/18.
//

#ifndef GRADIUS_VIEWS_BOSS_H
#define GRADIUS_VIEWS_BOSS_H

#include "Ship.h"

namespace resources{
    class Boss;
}

namespace views {
    class Boss : public Ship{
    protected:
        Animation m_normal = m_animation;
        Animation m_invincible = m_animation;
    public:
        friend class resources::Boss;

        void update();
    };
}


#endif //GRADIUS_VIEWS_BOSS_H
