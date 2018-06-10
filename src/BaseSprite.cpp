//
// Created by benji on 10/06/18.
//

#include <cmath>
#include "BaseSprite.h"

std::map<std::string, BaseSprite> sprites = {};

void BaseSprite::readFromIni(std::string path) {
    std::ifstream file(path);
    path = path.substr(0,path.rfind('/')+1);
    ini::Configuration configuration(file);

    m_nrFrames = configuration["General"]["nrFrames"].as_int_or_default(1);
    if(m_nrFrames <= 0){
        //Throw exception for invalid amount of frames
    }
    m_strip = configuration["General"]["isStrip"].as_bool_or_default(false); //represents whether an image contains multiple frames or not

    m_sourcePath = configuration["General"]["Source"].as_string_or_die();
    m_texture = std::make_shared<sf::Texture>();
    m_texture->loadFromFile(path+m_sourcePath);

    if(m_strip){
        m_frameWidth = configuration["General"]["frameWidth"].as_int_or_default(std::floor(m_texture->getSize().x/m_nrFrames)); //represents the width of a single frame in a strip
        m_frameOffset = configuration["General"]["frameOffset"].as_int_or_default(0); //represents the offset between two frames in a strip image
    }

    if(m_nrFrames > 1){
        m_delay = configuration["General"]["frameDelay"].as_int_or_default(0); //represents the delay between two frames of the sprite
    }

    auto origin = configuration["General"]["Origin"].as_int_tuple_or_default({0,0});
    m_origin = {origin[0], origin[1]};
}

Sprite BaseSprite::create() {
    Sprite sprite;
    sprite.m_sprites = {};
    if(m_strip){
        for(int i = 0; i < m_nrFrames; ++i){
            sprite.m_sprites.emplace_back(sf::Sprite(*m_texture, sf::IntRect{i*(m_frameWidth + m_frameOffset), 0,m_frameWidth,m_texture->getSize().y}));
        }
    }
    else{
        sprite.m_sprites = {sf::Sprite(*m_texture)};
    };
    sprite.m_delay = static_cast<unsigned int>(m_delay);
    sprite.setOrigin(m_origin);
    return sprite;
}
