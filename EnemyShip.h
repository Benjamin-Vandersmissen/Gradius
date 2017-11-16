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

        entities::EnemyShip* create(const std::pair<float, float>& position);
    };
}

namespace views {
    class EnemyShip : public EntityView{
    private:
        sf::Texture* m_texture;
    public:
        friend class resources::EnemyShip;

        EnemyShip(entities::Entity *associatedEntity);
    };
}
#endif //GRADIUS_ENEMYSHIP_H
