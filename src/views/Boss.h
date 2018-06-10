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
        Sprite m_normal = m_sprite;
        Sprite m_invincible = m_sprite;
    public:
        friend class resources::Boss;

        void update();
    };
}


#endif //GRADIUS_VIEWS_BOSS_H
