//
// Created by benji on 22.11.17.
//

#ifndef GRADIUS_VIEW_H
#define GRADIUS_VIEW_H

#include "Model.h"

namespace models{
    class Model;
}

namespace controllers{
    class Controller;
}

namespace views {

    class View {
    private:
        models::Model* m_model;
    public:
        void setModel(models::Model* model);

        void update();
    };

}


#endif //GRADIUS_VIEW_H
