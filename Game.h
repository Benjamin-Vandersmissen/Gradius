//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_GAME_H
#define GRADIUS_GAME_H

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "StopWatch.h"
#include "Entity.h"
#include "Transformation.h"

class Game : public sf::Drawable{
private:
    StopWatch* m_stopWatch = nullptr;
    sf::RenderWindow* m_window = nullptr;
    unsigned long m_updatedelay; //the time between two ticks (in millionths of a second)
    Transformation* transformation = nullptr;
    std::vector<entities::Entity*> m_entities;
public:
    /**
     * \brief creates a Game with default arguments
     * */
    Game();

    /**
     * \brief Will execute the gameloop
     * */
    void loop();

    /**
     * \brief Handles events, by giving them to entities
     * */
    int handleEvent(sf::Event &event);

    /**
     * \brief draws the game to the window
     * */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //GRADIUS_GAME_H
