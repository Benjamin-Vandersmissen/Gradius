//
// Created by benji on 14.11.17.
//

#ifndef GRADIUS_ENEMYSHIP_H
#define GRADIUS_ENEMYSHIP_H

#include "ScrollingEntity.h"
#include "EntityView.h"

namespace entities {
    class EnemyShip : public  ScrollingEntity{
    public:
        EnemyShip(const std::pair<float, float> &position, sf::Texture *texture, float speed);
    };
}

namespace views {
    class EnemyShip : public EntityView{
    private:
        sf::Texture* m_texture;
    public:
        EnemyShip(entities::Entity *associatedEntity);
    };
}
#endif //GRADIUS_ENEMYSHIP_H
