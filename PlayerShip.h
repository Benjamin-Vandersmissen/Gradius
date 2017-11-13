//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_PLAYERSHIP_H
#define GRADIUS_PLAYERSHIP_H

#include "Entity.h"

namespace entities {
    class PlayerShip : public Entity{
    public:
        PlayerShip(const std::pair<float, float> &position, sf::Texture *texture, float speed);

        virtual void handleEvent(sf::Event& event);

        //do actions when specific keys are pressed
        void handleKeyboard(sf::Event &event);

        virtual void update();
    };
}


#endif //GRADIUS_PLAYERSHIP_H
