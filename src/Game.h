//
// Created by benji on 22.11.17.
//

#ifndef GRADIUS_GAME_H
#define GRADIUS_GAME_H


#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "StopWatch.h"
#include "Transformation.h"
#include "json.hpp"
#include "ini_configuration.hh"
#include "resources/Entity.h"
#include "models/Model.h"


using json = nlohmann::json;

class Game {
private:
    StopWatch* m_stopwatch = StopWatch::getInstance();
    std::shared_ptr<models::Model> m_model;
    std::shared_ptr<views::View> m_view;
    std::shared_ptr<controllers::Controller> m_controller;

public:
    Game();

    void loop();

    void handleEvents();
};

resources::Entity* loadResource(std::string path, std::string resourceName);

void loadLevel(std::string fullPath);


#endif //GRADIUS_GAME_H
