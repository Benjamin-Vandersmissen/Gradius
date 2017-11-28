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
#include "PlayerBullet.h"
#include "Transformation.h"
#include "json.hpp"
#include "ini_configuration.hh"
#include "EnemyShip.h"


using json = nlohmann::json;

class Game {
private:
    sf::RenderWindow* m_window;
    bool m_paused = false;
    StopWatch* m_stopwatch = StopWatch::getInstance();
public:
    Game();

    void loop();

    void handleEvents();
};

resources::Entity* loadResource(std::string path, std::string resourceName);

void loadLevel(std::string fullPath);


#endif //GRADIUS_GAME_H
