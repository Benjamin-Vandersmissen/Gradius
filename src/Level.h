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
    /**
     * comparator for 2 levelobjects, returns whether the x-value of the first is lower than the x-value of the second
     * */
    bool operator()(levelObject obj1, levelObject obj2){return obj1.position.first < obj2.position.first;}
};

class Level {
private:
    std::multiset<levelObject, levelObject> m_objects; //contains all levelobjects sorted by x-position
    float m_speed;
    float m_length;
public:
    std::multiset<levelObject, levelObject> tempObjects; //contains the levelobjects of the current level that aren't loaded in yet

    /**
     * @brief create levelObjects from a file and load all needed resources
     * */
    void loadLevel(std::string fullPath);

    /**
     * @brief clear all active entities and load the level objects to tempObjects
     * */
    void initLevel();

    /**
     * @brief load a resource whith a given name in a given path
     * */
    resource_ptr loadResource(std::string path, std::string resourceName);

    float speed() const{
        return m_speed;
    }

    float length() const{
        return m_length;
    }

    /**
     * @brief create all entities where the x-value is lower than the bound. The position on screen is the position - currentX
     * */
    void dynamicLoad(float bound, float currentX);
};


#endif //GRADIUS_LEVEL_H
