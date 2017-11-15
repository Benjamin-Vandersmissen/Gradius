//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_PLAYERBULLET_H
#define GRADIUS_PLAYERBULLET_H

#include "Entity.h"
#include "EntityView.h"

namespace entities {
    class PlayerBullet : public Entity {
    public:
        PlayerBullet(const std::pair<float, float> &position, const sf::FloatRect &hitbox, float speed);

        void onCollision(Entity* entity);
    };
}

namespace views{
    class PlayerBullet : public EntityView{
    private:
        sf::Texture* m_texture;
    public:
        PlayerBullet(entities::Entity *associatedEntity);
    };
}


#endif //GRADIUS_PLAYERBULLET_H
