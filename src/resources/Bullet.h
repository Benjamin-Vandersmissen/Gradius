//
// Created by benji on 4/06/18.
//

#ifndef GRADIUS_RESOURCES_BULLET_H
#define GRADIUS_RESOURCES_BULLET_H

#include <SFML/Audio.hpp>
#include "Entity.h"

namespace resources {
    class Bullet : public Entity {
    protected:
        double m_speed;

        std::shared_ptr<sf::SoundBuffer> m_firedSoundBuffer;

        sf::Sound m_firedSound = sf::Sound();

    public:
        void loadFromIni(const std::string &path, const ini::Configuration &configuration) override;
    };
}


#endif //GRADIUS_BULLET_H
