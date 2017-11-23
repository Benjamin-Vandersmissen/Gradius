//
// Created by benji on 22.11.17.
//

#include "Game.h"
#include "ScrollingEntity.h"
#include "ini_configuration.hh"


Game::Game() {
    m_window = new sf::RenderWindow(sf::VideoMode(200,150), "Gradius ~ Test");
    Transformation::initTransformation(200,150);
    models::PlayerShip* model = new models::PlayerShip;

    loadLevel("../levels/level.json");

    auto view = new views::PlayerShip();
    auto controller = new controllers::PlayerShip();
    view->setModel(model);
    model->setController(controller);
    view->m_animation.createFromStrip("../resources/textures/PlayerShip_strip.png", 2);
    model->notify(); //synchronise the states
    models::list.push_back(model);
    controllers::list.push_back(controller);
    views::list.push_back(view);

    auto view2 = new views::ScrollingEntity();
    auto controller2 = new controllers::ScrollingEntity();
    models::ScrollingEntity* model2 = new models::ScrollingEntity;
    view2->setModel(model2);
    model2->setController(controller2);
    view2->m_animation.createFromStrip("../resources/textures/EnemyShip_strip.png", 3);
    model2->position(std::pair<float,float>{4,0});
    models::list.push_back(model2);
    controllers::list.push_back(controller2);
    views::list.push_back(view2);

}

void Game::loop() {
    while(m_window->isOpen()){
        if(m_paused){
            sf::Event event;
            while(m_window->pollEvent(event)){
                if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                    m_paused = !m_paused;
            }
            continue;
        }
        if(m_stopwatch->getElapsedTime() > 1000000/60){
            m_stopwatch->reset();
        }
        else{
            continue;
        }
        if(!m_window->hasFocus())
            continue;
        handleEvents();
        for(auto controller : controllers::list){
            controller->update();
        }
        m_window->clear();
        for(auto view : views::list){
            m_window->draw(*view);
        }
        m_window->display();
    }
}

void Game::handleEvents() {
    sf::Event event;
    while(m_window->pollEvent(event)){
        if(event.type == sf::Event::Closed)
            m_window->close();
        else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
            m_paused = !m_paused;
        }
        else{
            for (auto controller: controllers::list) {
                controller->handleEvent(event);
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

        if(resources::map.find(resource) == resources::map.end()){
            auto entity = resources::map[resource]->create();
            entity->position(position);
        }
    }
}

resources::Entity *loadResource(std::string path, std::string resourceName) {
    ini::Configuration config;
    std::ifstream stream(path+resourceName+".ini");
    stream >> config;
    std::string type = config["General"]["Type"].as_string_or_die();
    if (type == "PlayerShip"){
        auto resource  = new resources::PlayerShip;
        resource->loadFromIni(config);
        return resource;
    }
    if(type == "PlayerBullet"){
        double speed = config["General"]["Speed"].as_double_or_die();
        auto resource = new resources::PlayerBullet;
        resource->loadFromIni(config);
        return resource;
    }
}
