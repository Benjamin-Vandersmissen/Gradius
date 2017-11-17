//
// Created by benji on 13.11.17.
//

#include "Game.h"
#include "PlayerShip.h"
#include "EnemyShip.h"
#include "BorderObstacle.h"

resources::EntityResource *::resources::loadFromJson(std::string filename) {
    std::string path = filename.substr(0, filename.rfind("/")+1);
    json j;
    std::ifstream stream(filename);
    stream >> j;
    std::string type = j["Type"];
    if(type == "PlayerBullet"){
        PlayerBullet* bullet = new PlayerBullet;
        bullet->loadFromJson(j, path);
        return bullet;
    }
    else if (type == "PlayerShip"){
        PlayerShip* ship = new PlayerShip;
        ship->loadFromJson(j, path);
        return ship;
    }
    else if (type == "EnemyShip"){
        EnemyShip* ship = new EnemyShip;
        ship->loadFromJson(j, path);
        return ship;
    }
    else if (type == "BorderObstacle"){
        BorderObstacle* obstacle = new BorderObstacle;
        obstacle->loadFromJson(j, path);
        return obstacle;
    }
    else if (type == "Obstacle"){
        Obstacle* obstacle = new Obstacle;
        obstacle->loadFromJson(j, path);
        return obstacle;
    }
    return nullptr;
}

Game::Game(unsigned int width, unsigned int height) {
    m_stopWatch = StopWatch::getStopWatch();
    m_window = new sf::RenderWindow(sf::VideoMode(200, 150), "Gradius"); //the default size is 200x150, this will make it that everything is auto-scaled
    m_window->setSize({width,height});
    Transformation::initTransformation(200, 150);
    m_updatedelay = 1000000/100;
    loadLevel("../levels/level.json");
}

Game::Game() : Game(400, 300) {

}

void Game::loop() {
    while(m_window->isOpen()) {
        if(!m_window->hasFocus() || m_stopWatch->getElapsedTime() < m_updatedelay)
            continue;
        else if(m_stopWatch->getElapsedTime() >= m_updatedelay) {
            m_stopWatch->reset();
        }
        sf::Event event;
        while(m_window->pollEvent(event)){
            if(handleEvent(event) == -1){ //returnvalue == -1 => window is closed
                return;
            }
        }
        m_window->clear();
        for(int i = 0; i < entities::entityList.size(); i++){
            entities::Entity* entity = entities::entityList.at(i);
            entity->update();
        }
        for(int i = 0; i < views::viewList.size(); i++){
            views::EntityView* view = views::viewList.at(i);
            view->update();
        }
        views::deleteMarkedViews();
        entities::deleteMarkedEntities();
        m_window->draw(*this);
        m_window->display();
    }
}

int Game::handleEvent(sf::Event &event) {
    switch(event.type){
        case sf::Event::Closed:
            m_window->close();
            return -1;
        default:
            for(int i = 0; i < entities::entityList.size(); i++){
                entities::Entity* entity = entities::entityList[i];
                entity->handleEvent(event);
            }
    }
    return 0;
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(views::EntityView* view : views::viewList){
        target.draw(*view, states);
    }
}

void loadLevel(std::string filename) {
    json j;
    std::ifstream stream(filename);
    stream >> j;

    for(entities::Entity* entity: entities::entityList) {
        entity->markDeleted();
    }
    entities::deleteMarkedEntities();

    for(views::EntityView* view : views::viewList){
        view->markDeleted();
    }
    views::deleteMarkedViews();
    std::string resourcePath = j["ResourcePath"];
    if(resourcePath.back() != '/')
        resourcePath += '/';

    std::vector<json> entities = j["Entities"];

    using resources::resourceMap;
    resourceMap.clear();

    std::vector<std::string> resourcesToLoad = j["Resources"];
    for(std::string& type : resourcesToLoad){
        if(resourceMap.find(type) == resourceMap.end()){
            resources::EntityResource* resource = resources::loadFromJson(resourcePath+type+".json");
            if(resource == nullptr){

            }
            else{
                resourceMap[type] = resource;
            }
        }
    }

    for(json& j1 : entities){
        std::string type = j1["Type"];
        std::pair<float, float> position = j1["Position"];

        if(resourceMap.find(type) == resourceMap.end()){ //resource not loaded in yet
            resources::EntityResource* resource = resources::loadFromJson(resourcePath+type+".json");
            if(resource == nullptr){

            }
            else {
                resourceMap[type] = resource;
            }
        }

        resourceMap[type]->create(position);
    }
}
