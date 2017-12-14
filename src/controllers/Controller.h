//
// Created by uauser on 12/14/17.
//

#ifndef GRADIUS_CONTROLLER_H
#define GRADIUS_CONTROLLER_H

#include <memory>
#include "../models/Model.h"
#include "Entity.h"

namespace models{
    class Model;
}

namespace controllers{
    class Controller : public std::enable_shared_from_this<controllers::Controller>{
    private:
        std::shared_ptr<models::Model> m_model;
    public:
        void addModel(std::shared_ptr<models::Model> model);
    };
}


#endif //GRADIUS_CONTROLLER_H
