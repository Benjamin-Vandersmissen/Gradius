//
// Created by benji on 14.11.17.
//

#ifndef GRADIUS_ENEMYSHIP_H
#define GRADIUS_ENEMYSHIP_H

#include "ScrollingEntity.h"
#include "EntityView.h"
#include "EntityResource.h"

namespace entities {
    class EnemyShip : public  ScrollingEntity{
    public:
        EnemyShip(const std::pair<float, float> &position, const sf::FloatRect &hitbox, float speed);
    };
}

namespace resources{
    class EnemyShip : public EntityResource{
    public:
        EnemyShip();

        std::shared_ptr<entities::Entity> create(const std::pair<float, float>& position) override;
    };
}

namespace views {
    class EnemyShip : public EntityView{
    public:
        friend class resources::EnemyShip;

        explicit EnemyShip(std::shared_ptr<entities::Entity> associatedEntity);
    };
}
#endif //GRADIUS_ENEMYSHIP_H
