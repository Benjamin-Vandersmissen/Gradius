//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_GAME_H
#define GRADIUS_GAME_H

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "StopWatch.h"


class Game {
private:
    StopWatch* m_stopWatch = nullptr;
    sf::RenderWindow* m_window;
    unsigned long m_updatedelay; //the time between two ticks (in millionths of a second)
public:
    Game();

    void loop();

};


#endif //GRADIUS_GAME_H
