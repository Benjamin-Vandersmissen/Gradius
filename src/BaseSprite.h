//
// Created by benji on 10/06/18.
//

#ifndef GRADIUS_BASESPRITE_H
#define GRADIUS_BASESPRITE_H


#include <map>
#include <fstream>
#include <memory>
#include "ini_configuration.hh"
#include "Sprite.h"

class Sprite;

class BaseSprite {
private:
    int m_nrFrames;

    bool m_strip;

    int m_frameWidth;

    int m_frameOffset;

    std::string m_sourcePath;

    std::shared_ptr<sf::Texture> m_texture;

    int m_delay;

    sf::Vector2f m_origin;
public:
    /**
     * @brief read all information for the sprite in
     * */
    void readFromIni(std::string path);

    /**
     * @brief create a Sprite with the given parameters
     * */
    Sprite create();

};



extern std::map<std::string, BaseSprite> sprites;

#endif //GRADIUS_BASESPRITE_H
