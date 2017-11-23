//
// Created by benji on 22.11.17.
//

#ifndef GRADIUS_PLAYERSHIP_H
#define GRADIUS_PLAYERSHIP_H

#include "Entity.h"
#include "Animation.h"

namespace resources{
    class PlayerShip;
}

namespace views {
    class PlayerShip : public Entity{
    public:
        void update();

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override ;
    };
}

namespace models{
    class PlayerShip : public Entity{
    private:
        float m_speed = 0.08;
    public:
        friend class resources::PlayerShip;

        void update();

        void handleCollision(models::Entity*);
    };
}

namespace controllers{
    class PlayerShip : public Entity{
    private:
        std::pair<float, float> m_currentDirection;

        unsigned int m_fireCooldown = 0;

        unsigned int m_maxFireCooldown = 80;

        bool m_fired = false;
    public:
        void update();

        const std::pair<float, float> &currentDirection() const;

        void handleEvent(const sf::Event& event);

        bool fired();
    };
}

namespace resources {
    class PlayerShip : public Entity{
    private:
        double m_speed;

    public:
        void loadFromIni(ini::Configuration& configuration) override;

        models::PlayerShip* create();
    };
}


#endif //GRADIUS_PLAYERSHIP_H
