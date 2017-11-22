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

    public:

        void setModel(models::Model* model);

        void notify();
    };

}


#endif //GRADIUS_CONTROLLER_H
