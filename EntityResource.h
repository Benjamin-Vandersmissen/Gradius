//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_ENTITYRESOURCE_H
#define GRADIUS_ENTITYRESOURCE_H


#include "Entity.h"
#include "EntityView.h"

#include "json.hpp"
#include "ini_configuration.hh"
#include "Animation.h"
#include <fstream>
using json = nlohmann::json;

namespace resources {
    /**
     * Default resource, each resource will at least contain a texture, a hitbox and a speed
     * */
    class EntityResource {
    protected:
        sf::FloatRect m_hitbox;

        float m_speed;

        int m_nrFrames = 1;

        Animation m_animation;

        int m_delay = -1;

    public:
        EntityResource();

        EntityResource(Animation animation, const sf::FloatRect &hitbox, float speed);

        virtual void loadFromJson(json j, std::string path);

        virtual void loadFromIni(std::string path, std::string filename);

        virtual entities::Entity *create(const std::pair<float, float> &position) = 0;
    };

    extern std::map<std::string, EntityResource*> resourceMap;
}


#endif //GRADIUS_ENTITYRESOURCE_H
