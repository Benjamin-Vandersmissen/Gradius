//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_ENTITYRESOURCE_H
#define GRADIUS_ENTITYRESOURCE_H


#include "Entity.h"
#include "EntityView.h"

#include "json.hpp"
using json = nlohmann::json;

namespace resources {
    /**
     * Default resource, each resource will at least contain a texture, a hitbox and a speed
     * */
    class EntityResource {
    protected:
        sf::Texture* m_texture;

        sf::FloatRect m_hitbox;

        float m_speed;

    public:
        EntityResource();

        EntityResource(sf::Texture* texture, const sf::FloatRect& hitbox, float speed);

        virtual void loadFromJson(json j, std::string path);

        virtual entities::Entity *create(const std::pair<float, float> &position) = 0;
    };
}


#endif //GRADIUS_ENTITYRESOURCE_H
