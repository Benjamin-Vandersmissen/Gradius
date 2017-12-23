//
// Created by benji on 23.12.17.
//

#ifndef GRADIUS_LEVEL_H
#define GRADIUS_LEVEL_H

#include <string>
#include <vector>
#include <fstream>
#include "Exception.h"
#include "json.hpp"
#include "resources/Entity.h"

struct levelObject{
    std::string resource;
    std::pair<float, float> position;
};

//TODO : make it possible to load mutliple levels and only play one by using levelObjects
class Level {
private:
    std::vector<levelObject> m_objects;
    std::string m_resourcePath;
public:
    void loadLevel(std::string fullPath);

    resource_ptr loadResource(std::string path, std::string resourceName);
};


#endif //GRADIUS_LEVEL_H
