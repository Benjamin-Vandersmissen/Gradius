//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_RESOURCES_ENEMYBULLET_H
#define GRADIUS_RESOURCES_ENEMYBULLET_H

#include <SFML/Audio.hpp>
#include "Entity.h"

#include "../models/EnemyBullet.h"
#include "../controllers/EnemyBullet.h"

namespace resources{
    class EnemyBullet : public Entity{
    private:
        double m_speed;

        std::shared_ptr<sf::SoundBuffer> m_firedSoundBuffer;

        sf::Sound m_firedSound = sf::Sound();
    public:
        model_ptr create(const std::pair<float, float> &position) override;

        void loadFromIni(const std::string &path, const ini::Configuration &configuration) override;
    };
}

#endif //GRADIUS_RESOURCES_ENEMYBULLET_H
