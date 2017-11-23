//
// Created by benji on 23.11.17.
//

#include "EnemyShip.h"

void resources::EnemyShip::loadFromIni(std::string path, ini::Configuration &configuration) {
    Entity::loadFromIni(path, configuration);
}

models::EnemyShip *resources::EnemyShip::create(const std::pair<float, float> &position) {
    auto model = new models::EnemyShip;

    auto view = new views::EnemyShip;
    auto controller = new controllers::EnemyShip;
    model->setController(controller);
    view->setModel(model);
    setAnimationOfView(view);

    model->position(position);
    model->notify();
    
    models::list.push_back(model);
    views::list.push_back(view);
    controllers::list.push_back(controller);
    return model;
}
