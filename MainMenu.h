//
// Created by uauser on 11/30/17.
//

#ifndef GRADIUS_MAINMENU_H
#define GRADIUS_MAINMENU_H


#include "Entity.h"

namespace views {
    class MainMenu : public Entity{

    };
}

namespace models {
    class MainMenu : public Entity{
    private:
        int m_selectedState = states::play;
    public:
        enum states{
            play,
            levelSelect,
            exit,
            END
        };

        void update();
    };
}

namespace controllers {
    class MainMenu : public Entity{
    private:
        int m_direction = 0;
    public:
        void update();

        void handleEvent(const sf::Event& event);

        int direction();
    };
}


#endif //GRADIUS_MAINMENU_H
