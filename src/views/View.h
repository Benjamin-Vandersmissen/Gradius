//
// Created by uauser on 12/14/17.
//

#ifndef GRADIUS_VIEW_H
#define GRADIUS_VIEW_H

#include "../models/Model.h"
#include "Entity.h"

namespace models{
    class Model;
}
namespace views {
    class View : public std::enable_shared_from_this<views::View>{
    private:
        std::shared_ptr<models::Model> m_model;

        std::shared_ptr<sf::RenderWindow> m_window;

        std::shared_ptr<sf::Font> m_defaultFont;

        sf::CircleShape m_menuSelector;
    public:
        View(unsigned int width, unsigned int height, const std::string &title);

        void setModel(std::shared_ptr<models::Model> model);

        void update();

        std::shared_ptr<sf::RenderWindow> window() const;

        void draw();
    };
}


#endif //GRADIUS_VIEW_H
