//
// Created by benji on 22.11.17.
//

#ifndef GRADIUS_ENTITY_H
#define GRADIUS_ENTITY_H

#include <memory>
#include "Model.h"

namespace views{
    class Entity;
}

namespace controllers{
    class Entity;
}

namespace models {
    class Entity {
    private:
        std::shared_ptr<views::Entity> m_view;

        std::shared_ptr<controllers::Entity> m_controller;

        std::pair<float, float> m_position;
    public:
        void addView(std::shared_ptr<views::Entity> view);

        void setController(std::shared_ptr<controllers::Entity> controller);

        virtual void update() =0;

        void notify();
    };
}

namespace views{
    class Entity {
    private:
        models::Entity* m_model;

    public:
        void setModel(models::Entity *model);

        virtual void update() =0;
    };
}

namespace controllers{
    class Entity{
    private:
        models::Entity* m_model;

    public:
        void addModel(models::Entity* model);

        virtual void update() =0;

        void notify();
    };
}


#endif //GRADIUS_ENTITY_H
