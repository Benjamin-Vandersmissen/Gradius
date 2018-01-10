//
// Created by benji on 23.12.17.
//

#include "Level.h"
#include "resources/PlayerShip.h"
#include "resources/PlayerBullet.h"
#include "resources/EnemyBullet.h"
#include "resources/BorderObstacle.h"
#include "resources/Obstacle.h"

using json = nlohmann::json;

void Level::loadLevel(std::string fullPath) {
    std::ifstream stream(fullPath);

    resources::map.clear();
    m_objects.clear();

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
            m_objects.insert(levelObject{resource,position});
        }
        catch(std::exception& e){
            throw ResourceException(ResourceException::missingResource, resource);
        }
    }
    std::string border = j["Border"];
    resource_ptr borderResource = resources::map.at(border);
    float f = Transformation::left();
    while(true){ //create a border
        sf::FloatRect hitbox =borderResource->hitbox();
        m_objects.insert(levelObject{border, std::pair<float,float>{f, Transformation::top()}});
        m_objects.insert(levelObject{border, std::pair<float,float>{f, Transformation::top()+Transformation::height()-hitbox.height}});
        if(f >= Transformation::width()+ Transformation::left() + hitbox.width)
            break;
        f += hitbox.width;
    }
    m_speed = j["Speed"];
    m_length = j["Length"];
}

resource_ptr Level::loadResource(std::string path, std::string resourceName) {
    ini::Configuration config;
    std::ifstream stream(path+resourceName+".ini");
    stream >> config;
    std::string type = config["General"]["Type"].as_string_or_die();
    resource_ptr resource = nullptr;
    if (type == "PlayerShip"){
        resource  = std::make_shared<resources::PlayerShip>();
    }
    if(type == "PlayerBullet"){
        resource = std::make_shared<resources::PlayerBullet>();
    }
    if (type == "EnemyShip"){
        resource = std::make_shared<resources::EnemyShip>();
    }
    if(type == "BorderObstacle"){
        resource = std::make_shared<resources::BorderObstacle>();
    }
    if(type == "Obstacle"){
        resource = std::make_shared<resources::Obstacle>();
    }
    if(type == "EnemyBullet"){
        resource = std::make_shared<resources::EnemyBullet>();
    }
    if(resource){
        resource->loadFromIni(path, config);
        return resource;
    }
    throw ResourceException(ResourceException::unknownClass, resourceName, type);
}

void Level::initLevel() {
    views::list.clear();
    models::list.clear();
    controllers::list.clear();
    tempObjects = m_objects;
}

void Level::dynamicLoad(float x) {
    for(auto obj = tempObjects.begin(); obj != tempObjects.end() && (*obj).position.first <= x;){
        resources::map[(*obj).resource]->create((*obj).position);
        obj = tempObjects.erase(obj);
    }
}
