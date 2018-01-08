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
        Animation m_animation; //the default animation for the view
        sf::FloatRect m_hitbox; //the local hitbox
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
         * @brief give a view the stored animation
         *
         * @param view the view
         * */
        void setAnimationOfView(view_ptr view);

        /**
         * @brief link the model, view and controller in the MVC structure, move them to the correct position and add them to the game
         * */
        void finalizeCreation(view_ptr view, model_ptr model, controller_ptr controller,
                              std::pair<float, float> position);

        sf::FloatRect hitbox() const {return m_hitbox;}
    };


    extern std::map<std::string, resource_ptr> map;
}


#endif //GRADIUS_ENTITY_H
