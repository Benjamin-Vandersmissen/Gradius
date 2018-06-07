//
// Created by benji on 7/06/18.
//

#ifndef GRADIUS_MODELS_BOSS_1_H
#define GRADIUS_MODELS_BOSS_1_H

#include "Boss.h"
#include "../resources/Boss.h"

namespace resources{
    class Boss;
}

namespace models {
    class Boss_1 : public Boss{
    private:
        std::string m_minion;
    public:
        friend class resources::Boss;

        std::string getMinionType() const;
    };
}

#endif //GRADIUS_MODELS_BOSS_1_H
