//
// Created by benji on 23.11.17.
//

#ifndef GRADIUS_ENEMYSHIP_H
#define GRADIUS_ENEMYSHIP_H

#include "Entity.h"
#include "ScrollingEntity.h"

namespace resources{
    class EnemyShip;
}

namespace views {
    class EnemyShip : public ScrollingEntity{

    };
}

namespace models {
    class EnemyShip : public ScrollingEntity{
    public:
        friend class resources::EnemyShip;

        void handleCollision(model_ptr entity) override;
    };
}

namespace controllers {
    class EnemyShip : public ScrollingEntity{

    };
}

namespace resources {
    class EnemyShip : public Entity{
    public:
        void loadFromIni(std::string path, ini::Configuration& configuration);

        model_ptr create(const std::pair<float, float> &position);
    };
}


#endif //GRADIUS_ENEMYSHIP_H
