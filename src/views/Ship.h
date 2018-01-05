//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_PLAYERSHIP_H
#define GRADIUS_PLAYERSHIP_H

#include "Entity.h"

#include "../resources/PlayerShip.h"

namespace resources{
    class PlayerShip;
}
namespace resources{
    class EnemyShip;
}

namespace views {
    class Ship : public Entity{
    private:
        std::shared_ptr<sf::Texture> m_heartTexture;
    public:
        friend class resources::PlayerShip;
        friend class resources::EnemyShip;

        void update() override;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override ;
    };
}


#endif //GRADIUS_PLAYERSHIP_H
