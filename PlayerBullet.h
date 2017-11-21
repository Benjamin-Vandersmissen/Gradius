//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_PLAYERBULLET_H
#define GRADIUS_PLAYERBULLET_H

#include "Entity.h"
#include "EntityView.h"
#include "EntityResource.h"

namespace entities {
    class PlayerBullet : public Entity {
    public:
        PlayerBullet(const std::pair<float, float> &position, const sf::FloatRect &hitbox, float speed);

        void onCollision(Entity* entity);
    };
}

namespace resources{
    class PlayerBullet : public EntityResource{
    public:
        PlayerBullet();

        PlayerBullet(Animation *animation, const sf::FloatRect &hitbox, float speed);

        entities::PlayerBullet *create(const std::pair<float, float> &position);

    };
}

namespace views{
    class PlayerBullet : public EntityView{
    public:
        friend class resources::PlayerBullet;

        PlayerBullet(entities::Entity *associatedEntity);
    };
}


#endif //GRADIUS_PLAYERBULLET_H
