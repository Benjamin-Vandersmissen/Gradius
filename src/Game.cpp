//
// Created by benji on 22.11.17.
//

#include "Game.h"
#include "resources/EnemyShip.h"
#include "resources/Obstacle.h"
#include "resources/PlayerShip.h"
#include "resources/PlayerBullet.h"
#include "resources/BorderObstacle.h"
#include "resources/EnemyBullet.h"


Game::Game() {
    m_window = new sf::RenderWindow(sf::VideoMode(200,150), "Gradius ~ Test");
    Transformation::initTransformation(200,150);
    m_window->setSize({800,600});
    loadLevel("../levels/level.json");

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
        for(const auto& controller : controllers::list){
            controller->update();
        }
        models::deleteMarkedEntities();
        m_window->clear();
        for(const auto& view : views::list){
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
                for(const auto& view : views::list){
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
                    for (const auto& controller: controllers::list) {
                        controller->handleEvent(event);
                    }
                }
                break;
            }
            default: {
                if(m_paused)
                    break;
                for (const auto& controller: controllers::list) {
                    controller->handleEvent(event);
                }
                break;
            }
        }
    }
}

void loadLevel(std::string fullPath) {
    std::ifstream stream(fullPath);

    if(!stream.good()){ //!stream.good() != stream.bad()
        throw LevelException(LevelException::missingFile, fullPath);
    }
    std::string path = fullPath.substr(0, fullPath.rfind('/')+1);
    json j;
    stream >> j;

    std::string resourcePath;
    try {
        resourcePath = j["ResourcePath"];
    } catch(json::exception& e){
        throw LevelException(LevelException::missingEntry, fullPath, "ResourcePath");
    }


    std::vector<std::string> resources;
    try {
        resources = j["Resources"].get<std::vector<std::string> >();
    } catch(json::exception& e){
        throw LevelException(LevelException::missingEntry, fullPath, "Resources");
    }
    views::list.clear();
    models::list.clear();
    controllers::list.clear();
    resources::map.clear();

    for(const std::string& resource : resources){
        resources::map[resource] = loadResource(path+resourcePath, resource);
    }

    std::vector<json> entities;
    try {
        entities = j["Entities"].get<std::vector<json> >();
    } catch(json::exception& e){
        throw LevelException(LevelException::missingEntry, fullPath, "Entities");
    }
    for(json j1 : entities){
        std::pair<float,float> position = j1["Position"];
        std::string resource = j1["Type"];
        if(resources::map.find(resource) == resources::map.end()){
            resources::map[resource] = loadResource(path+resourcePath, resource);
        }
        try{
         auto entity = resources::map.at(resource)->create(position);
        }
        catch(std::exception& e){
            throw ResourceException(ResourceException::missingResource, resource);
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
    if(type == "EnemyBullet"){
        resource = new resources::EnemyBullet;
    }
    if(resource){
        resource->loadFromIni(path, config);
        return resource;
    }
    throw ResourceException(ResourceException::unknownClass, resourceName, type);
}