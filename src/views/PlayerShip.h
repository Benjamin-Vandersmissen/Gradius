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

namespace views {
    class PlayerShip : public Entity{
    private:
        std::shared_ptr<sf::Font> m_font;
        sf::Text m_text;
    public:
        void initText();

        friend class resources::PlayerShip;

        void update();

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override ;
    };
}


#endif //GRADIUS_PLAYERSHIP_H
