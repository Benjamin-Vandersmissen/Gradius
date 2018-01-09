//
// Created by benji on 23.12.17.
//

#ifndef GRADIUS_LEVEL_H
#define GRADIUS_LEVEL_H

#include <string>
#include <set>
#include <fstream>
#include "Exception.h"
#include "json.hpp"
#include "resources/Entity.h"

struct levelObject{
    std::string resource;
    std::pair<float, float> position;
    bool operator()(levelObject obj1, levelObject obj2){return obj1.position.first < obj2.position.first;}
};

class Level {
private:
    std::multiset<levelObject, levelObject> m_objects;
    std::string m_resourcePath;
    float m_speed;
    float m_length;
public:
    std::multiset<levelObject, levelObject> tempObjects;

    void loadLevel(std::string fullPath);

    void initLevel();

    resource_ptr loadResource(std::string path, std::string resourceName);

    float speed() const{
        return m_speed;
    }

    float length() const{
        return m_length;
    }

    void dynamicLoad(float x);
};


#endif //GRADIUS_LEVEL_H
