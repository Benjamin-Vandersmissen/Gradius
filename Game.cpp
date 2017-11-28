//
// Created by benji on 22.11.17.
//

#include "Game.h"
#include "Obstacle.h"
#include "BorderObstacle.h"


Game::Game() {
    m_window = new sf::RenderWindow(sf::VideoMode(200,150), "Gradius ~ Test");
    Transformation::initTransformation(200,150);
    models::PlayerShip* model = new models::PlayerShip;

    loadLevel("../levels/level.json");

//    auto view = new views::PlayerShip();
//    auto controller = new controllers::PlayerShip();
//    view->setModel(model);
//    model->setController(controller);
//    view->m_animation.createFromStrip("../resources/textures/PlayerShip_strip.png", 2);
//    model->notify(); //synchronise the states
//    models::list.push_back(model);
//    controllers::list.push_back(controller);
//    views::list.push_back(view);
//
//    auto view2 = new views::ScrollingEntity();
//    auto controller2 = new controllers::ScrollingEntity();
//    models::ScrollingEntity* model2 = new models::ScrollingEntity;
//    view2->setModel(model2);
//    model2->setController(controller2);
//    view2->m_animation.createFromStrip("../resources/textures/EnemyShip_strip.png", 3);
//    model2->position(std::pair<float,float>{4,0});
//    models::list.push_back(model2);
//    controllers::list.push_back(controller2);
//    views::list.push_back(view2);

}

void Game::loop() {
    while(m_window->isOpen()){
        if(m_stopwatch->getElapsedTime() > 1000000/60){
            m_stopwatch->reset();
        }
        else{
            continue;
        }
        if(!m_window->hasFocus())
            continue;
        handleEvents();
        if(m_paused)
            continue;
        for(auto controller : controllers::list){
            controller->update();
        }
        models::deleteMarkedEntities();
        m_window->clear();
        for(auto view : views::list){
            view->updateAnimation();
            m_window->draw(*view);
        }
        m_window->display();
    }
}

void Game::handleEvents() {
    sf::Event event;
    while(m_window->pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed: {
                m_window->close();
                break;
            }
            case sf::Event::Resized: {
                m_window->clear();
                for(auto view : views::list){
                    m_window->draw(*view);
                }
                m_window->display();
                break;
            }
            case sf::Event::KeyPressed: {
                if(event.key.code == sf::Keyboard::Escape){
                    m_paused = !m_paused;
                }
                if(!m_paused) {
                    for (auto controller: controllers::list) {
                        controller->handleEvent(event);
                    }
                }
                break;
            }
            default: {
                if(m_paused)
                    break;
                for (auto controller: controllers::list) {
                    controller->handleEvent(event);
                }
                break;
            }
        }
    }
}

void loadLevel(std::string fullPath) {
    std::ifstream stream(fullPath);
    std::string path = fullPath.substr(0, fullPath.rfind('/')+1);
    json j;
    stream >> j;
    std::string resourcePath = j["ResourcePath"];
    std::vector<std::string> resources = j["Resources"];

    views::list.clear();
    models::list.clear();
    controllers::list.clear();
    resources::map.clear();

    for(std::string resource : resources){
        resources::map[resource] = loadResource(path+resourcePath, resource);
    }

    std::vector<json> entities = j["Entities"];
    for(json j1 : entities){
        std::pair<float,float> position = j1["Position"];
        std::string resource = j1["Type"];
        if(resources::map.find(resource) == resources::map.end()){
            resources::map[resource] = loadResource(path+resourcePath, resource);
        }

        if(resources::map[resource] != nullptr){
            auto entity = resources::map[resource]->create(position);
        }
    }
}

resources::Entity *loadResource(std::string path, std::string resourceName) {
    ini::Configuration config;
    std::ifstream stream(path+resourceName+".ini");
    stream >> config;
    std::string type = config["General"]["Type"].as_string_or_die();
    resources::Entity* resource = nullptr;
    if (type == "PlayerShip"){
        resource  = new resources::PlayerShip;
    }
    if(type == "PlayerBullet"){
        resource = new resources::PlayerBullet;
    }
    if (type == "EnemyShip"){
        resource = new resources::EnemyShip;
    }
    if(type == "BorderObstacle"){
        resource = new resources::BorderObstacle;
    }
    if(type == "Obstacle"){
        resource = new resources::Obstacle;
    }
    if(resource){
        resource->loadFromIni(path, config);
        return resource;
    }
    return nullptr;
}
