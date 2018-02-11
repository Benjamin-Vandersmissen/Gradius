//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_RESOURCES_PLAYERBULLET_H
#define GRADIUS_RESOURCES_PLAYERBULLET_H

#include "Entity.h"

#include "../models/PlayerBullet.h"
#include "../controllers/PlayerBullet.h"
#include "SFML/Audio.hpp"


namespace resources{
    class PlayerBullet : public Entity{
    private:
        double m_speed;

        std::shared_ptr<sf::SoundBuffer> m_firedSoundBuffer;

        sf::Sound m_firedSound = sf::Sound();
    public:
        model_ptr create(const std::pair<float, float> &position) override;

        void loadFromIni(const std::string &path, const ini::Configuration &configuration) override;
    };
}

#endif //GRADIUS_RESOURCES_PLAYERBULLET_H
