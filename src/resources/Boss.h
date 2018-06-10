//
// Created by benji on 3/06/18.
//

#ifndef GRADIUS_RESOURCES_BOSS_H
#define GRADIUS_RESOURCES_BOSS_H

#include "../models/Boss.h"
#include "../controllers/Boss.h"
#include "EnemyShip.h"
#include "../views/Boss.h"

namespace resources {
    class Boss : public EnemyShip{
    protected:
        Sprite m_invincibleSprite;

        unsigned int m_bossType;

        std::string m_minionType;

    public:
        model_ptr create(const std::pair<float, float>& position) override ;

        void loadFromIni(const std::string &path, const ini::Configuration &configuration) override;

    };

}


#endif //GRADIUS_BOSS_H
