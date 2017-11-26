//
// Created by uauser on 11/23/17.
//

#ifndef GRADIUS_PLAYERBULLET_H
#define GRADIUS_PLAYERBULLET_H

#include "Entity.h"

namespace resources{
    class PlayerBullet;
}

namespace views {
    class PlayerBullet : public Entity {
    public:
        PlayerBullet();

    };

}

namespace models {
    class PlayerBullet : public Entity {
    private:
        double m_speed = 0.12;
    public:
        friend class resources::PlayerBullet;

        void update();

        void handleCollision(models::Entity* entity) override;
    };
}

namespace controllers {
    class PlayerBullet : public Entity {
    private:
        std::pair<float, float> m_currentDirection = {1,0};

    public:
        const std::pair<float, float>& currentDirection() const;

        void update(){
            notify();
        };
    };
}

namespace resources{
    class PlayerBullet : public Entity{
    private:
        double m_speed;
    public:
        models::PlayerBullet *create(const std::pair<float, float> &position);

        void loadFromIni(std::string path, ini::Configuration &configuration) override;
    };
}

#endif //GRADIUS_PLAYERBULLET_H
