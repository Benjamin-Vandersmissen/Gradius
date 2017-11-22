//
// Created by benji on 22.11.17.
//

#ifndef GRADIUS_CONTROLLER_H
#define GRADIUS_CONTROLLER_H

#include "Model.h"

namespace models{
    class Model;
}

namespace views{
    class View;
}

namespace controllers {

    class Controller {
    private:
        models::Model* m_model;

        std::shared_ptr<views::View> m_view;
    public:

        void setModel(models::Model* model);

        void setView(const std::shared_ptr<views::View>& view);

        void notify();

        bool update();
    };

}


#endif //GRADIUS_CONTROLLER_H
