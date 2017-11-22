//
// Created by benji on 22.11.17.
//

#ifndef GRADIUS_GAME_H
#define GRADIUS_GAME_H


#include "Model.h"

class Game {
private:
    models::Model* m_model;
    std::shared_ptr<views::View> m_view;
    std::shared_ptr<controllers::Controller> m_controller;
public:
    Game();

    void loop();
};


#endif //GRADIUS_GAME_H
