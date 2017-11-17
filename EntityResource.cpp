//
// Created by benji on 13.11.17.
//

#include "EntityResource.h"

std::map<std::string, resources::EntityResource*> resources::resourceMap = {};

resources::EntityResource::EntityResource() {}

void resources::EntityResource::loadFromJson(json j, std::string path) {
    std::string texturePath = j["TexturePath"];
    this->m_texture = new sf::Texture;
    if(!m_texture->loadFromFile(path+texturePath)) throw "A";

    m_speed = j["Speed"];
    std::pair<float,float> dimensions;
    dimensions.first = Transformation::width()*m_texture->getSize().x/Transformation::screenWidth();
    dimensions.second = Transformation::height()*m_texture->getSize().y/Transformation::screenHeight();
    m_hitbox = {0,0,dimensions.first, dimensions.second};
}

resources::EntityResource::EntityResource(sf::Texture *texture, const sf::FloatRect &hitbox, float speed): m_texture(texture), m_hitbox(hitbox), m_speed(speed) {

}

void resources::EntityResource::loadFromIni(std::string path, std::string filename) {
    std::ifstream stream(path+filename);
    ini::Configuration configuration(stream);
    std::string texturePath = configuration["General"]["TexturePath"].as_string_or_die();
    this->m_texture = new sf::Texture;
    if(!m_texture->loadFromFile(path+texturePath)) throw "A";

    m_speed = static_cast<float>(configuration["General"]["Speed"].as_double_or_die());

    std::pair<float,float> dimensions;
    dimensions.first = Transformation::width()*m_texture->getSize().x/Transformation::screenWidth();
    dimensions.second = Transformation::height()*m_texture->getSize().y/Transformation::screenHeight();
    m_hitbox = {0,0,dimensions.first, dimensions.second};
}
