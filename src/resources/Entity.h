//
// Created by benji on 09.12.17.
//

#ifndef GRADIUS_RESOURCES_ENTITY_H
#define GRADIUS_RESOURCES_ENTITY_H

#include <map>
#include <memory>
#include <fstream>

#include "../ini_configuration.hh"
#include "../Exception.h"

#include "../models/Entity.h"
#include "../views/Entity.h"
#include "../controllers/Entity.h"

namespace models{
    class Entity;
}

using model_ptr = std::shared_ptr<models::Entity>;

namespace views{
    class Entity;
}

using view_ptr = std::shared_ptr<views::Entity>;

namespace controllers{
    class Entity;
}

using controller_ptr = std::shared_ptr<controllers::Entity>;

namespace resources{
    class Entity;
}

using resource_ptr = std::shared_ptr<resources::Entity>;

namespace resources{
    class Entity: public std::enable_shared_from_this<resources::Entity>{
    protected:
        Hitbox m_hitbox = Hitbox(); //the local hitbox
        Sprite m_sprite = Sprite(); //the sprite
        int m_depth;
    public:
        /**
         * @brief create a new entity (model, view and controller) with the current parameters at the given position
         *
         * @param position the position for the new entity
         * */
        virtual model_ptr create(const std::pair<float, float> &position) =0;

        /**
         * @brief load parameters from an ini configuration
         *
         * @param path the root directory of the ini file
         *
         * @param configuration the configuration which contains all necessary data
         * */
        virtual void loadFromIni(const std::string &path, const ini::Configuration &configuration);

        /**
         * @brief link the model, view and controller in the MVC structure, move them to the correct position and add them to the game
         * */
        void finalizeCreation(view_ptr view, model_ptr model, controller_ptr controller,
                              std::pair<float, float> position);

        /**
         * @brief return the hitbox
         * */
        Hitbox hitbox() const {return m_hitbox;}

        /**
         * @brief read a list of coordinates from ini and construct a Hitbox based on it
         * */
        void createHitbox(const ini::Configuration& config);

    };

    // here are all resources saved under their resource name
    extern std::map<std::string, resource_ptr> map;
}


#endif //GRADIUS_ENTITY_H
