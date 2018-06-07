//
// Created by benji on 7/06/18.
//

#ifndef GRADIUS_CONTROLLERS_BOSS_1_H
#define GRADIUS_CONTROLLERS_BOSS_1_H


#include "Boss.h"


namespace controllers {
    class Boss_1 : public Boss{
    private:
        int m_stage = Stage ::EnteringBattlefield;

        std::pair<float, float> m_startPosition;

        int m_direction = -1 + 2*(rand()%2);

    public:
        enum Stage{
            EnteringBattlefield,
            Invincible,
            DamageTaken,
            Firing
        };

        void update();

        void spawnMinions();

    };
}


#endif //GRADIUS_BOSS_1_H
