//
// Created by benji on 22.11.17.
//

#ifndef GRADIUS_MODEL_H
#define GRADIUS_MODEL_H

#include <memory>
#include <set>
#include <iostream>
#include "Controller.h"
#include "View.h"

namespace views{
    class View;
}

namespace controllers{
    class Controller;
}

namespace models {

    class Model {
    private:
        std::shared_ptr<controllers::Controller> m_controller;

        std::set<std::shared_ptr<views::View> > m_views;
    public:

        void notify();

        void update();

        void addView(std::shared_ptr<views::View> view);

        void setController(const std::shared_ptr<controllers::Controller>& controller);
    };

}


#endif //GRADIUS_MODEL_H
