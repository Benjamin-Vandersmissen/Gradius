//
// Created by benji on 22.11.17.
//

#ifndef GRADIUS_VIEW_H
#define GRADIUS_VIEW_H

#include "Model.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

namespace models{
    class Model;
}

namespace controllers{
    class Controller;
}

namespace views {

    class View : public sf::Drawable{
    private:
        models::Model* m_model;

        sf::RenderWindow* m_window;
    public:
        View(unsigned int width, unsigned int height);

        void setModel(models::Model* model);

        void update();

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        sf::RenderWindow * window();
    };

}


#endif //GRADIUS_VIEW_H
