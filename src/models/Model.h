//
// Created by uauser on 12/14/17.
//

#ifndef GRADIUS_MODEL_H
#define GRADIUS_MODEL_H

#include <memory>
#include "Entity.h"
#include "../views/View.h"
#include "../controllers/Controller.h"

namespace views{
    class View;
}

namespace controllers{
    class Controller;
}

namespace models {
    class Model : public std::enable_shared_from_this<models::Model>{
    private:
        std::shared_ptr<views::View> m_view;
        std::shared_ptr<controllers::Controller> m_controller;
        bool m_paused = false;
        bool m_exit = false;
    public:
        void addView(std::shared_ptr<views::View> view);

        void setController(std::shared_ptr<controllers::Controller> controller);

        void update();

        void notify();

        bool paused() const {return m_paused;}

        bool exit() const {return m_exit;}
    };
}


#endif //GRADIUS_MODEL_H
