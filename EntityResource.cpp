//
// Created by benji on 13.11.17.
//

#include "EntityResource.h"

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
