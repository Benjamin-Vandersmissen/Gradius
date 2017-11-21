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

        void onCollision(Entity* entity) override;
    };
}

namespace resources{
    class PlayerBullet : public EntityResource{
    public:
        PlayerBullet();

        PlayerBullet(Animation animation, const sf::FloatRect &hitbox, float speed);

        std::shared_ptr<entities::Entity> create(const std::pair<float, float> &position) override;

    };
}

namespace views{
    class PlayerBullet : public EntityView{
    public:
        friend class resources::PlayerBullet;

        explicit PlayerBullet(std::shared_ptr<entities::Entity> associatedEntity);
    };
}


#endif //GRADIUS_PLAYERBULLET_H
