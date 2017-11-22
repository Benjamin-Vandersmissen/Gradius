//
// Created by benji on 22.11.17.
//

#ifndef GRADIUS_GAME_H
#define GRADIUS_GAME_H


#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Entity.h"
#include "StopWatch.h"
#include "PlayerShip.h"
#include "Transformation.h"

class Game {
private:
    std::vector<std::shared_ptr<views::Entity> > m_views;
    std::vector<std::shared_ptr<controllers::Entity> > m_controllers;
    std::vector<models::Entity*> m_models;
    sf::RenderWindow* m_window;
    bool m_closed = false;
    StopWatch* m_stopwatch = StopWatch::getStopWatch();
public:
    Game();

    void loop();

    void handleEvents();
};


#endif //GRADIUS_GAME_H
