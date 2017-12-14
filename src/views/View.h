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
    public:
        void setModel(std::shared_ptr<models::Model> model);

        void update();
    };
}


#endif //GRADIUS_VIEW_H
