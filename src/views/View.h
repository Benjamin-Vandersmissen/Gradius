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
        std::shared_ptr<models::Model> m_model; // a pointer to the model

        std::shared_ptr<sf::RenderWindow> m_window; //the window

        std::shared_ptr<sf::Font> m_defaultFont; // the default font

        sf::CircleShape m_menuSelector; // a triangle that will indicate which menu entry is selected
    public:
        /**
         * @brief create a view
         *
         * @param width the width of the window (in px)
         *
         * @param height the height of the window (in px)
         *
         * @param title the title of the window
         * */
        View(unsigned int width, unsigned int height, const std::string &title);

        /**
         * @brief set the model for MVC structure
         * */
        void setModel(std::shared_ptr<models::Model> model);

        /**
         * @brief update the internal state
         * */
        void update();

        /**
         * @brief return the window
         * */
        std::shared_ptr<sf::RenderWindow> window() const;

        /**
         * @brief clear the window and redraw eveything to the window
         * */
        void draw();

        /**
         * draws the currently open menu
         * */
        void drawMenu();
    };
}


#endif //GRADIUS_VIEW_H
