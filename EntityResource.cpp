//
// Created by benji on 13.11.17.
//

#include "EntityResource.h"

std::map<std::string, resources::EntityResource*> resources::resourceMap = {};

resources::EntityResource::EntityResource() = default;

void resources::EntityResource::loadFromJson(const json &j, const std::string &path) {
//    std::string texturePath = j["TexturePath"];
//    this->m_texture = new sf::Texture;
//    if(!m_texture->loadFromFile(path+texturePath)) throw "A";
//
//    m_speed = j["Speed"];
//    std::pair<float,float> dimensions;
//    dimensions.first = Transformation::width()*m_texture->getSize().x/ Transformation::windowWidth();
//    dimensions.second = Transformation::height()*m_texture->getSize().y/ Transformation::windowHeight();
//    m_hitbox = {0,0,dimensions.first, dimensions.second};
}

resources::EntityResource::EntityResource(Animation animation, const sf::FloatRect &hitbox, float speed): m_animation(animation), m_hitbox(hitbox), m_speed(speed) {

}

void resources::EntityResource::loadFromIni(const std::string &path, const std::string &filename) {
    std::ifstream stream(path+filename);
    ini::Configuration configuration(stream);
    std::string texturePath = configuration["General"]["TexturePath"].as_string_or_die();

    configuration["General"]["Delay"].as_int_if_exists(m_delay);

    configuration["General"]["NrFrames"].as_int_if_exists(m_nrFrames);

    m_animation = Animation(m_delay);
    m_animation.createFromStrip(path+texturePath, m_nrFrames);

    m_speed = static_cast<float>(configuration["General"]["Speed"].as_double_or_die());

    std::pair<float,float> dimensions;
    dimensions.first = Transformation::width()*m_animation.getSize().x/ Transformation::windowWidth();
    dimensions.second = Transformation::height()*m_animation.getSize().y/ Transformation::windowHeight();
    m_hitbox = {0,0,dimensions.first, dimensions.second};
}
