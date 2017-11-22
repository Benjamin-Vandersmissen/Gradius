//
// Created by benji on 22.11.17.
//

#ifndef GRADIUS_ENTITY_H
#define GRADIUS_ENTITY_H

#include <memory>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Drawable.hpp>

namespace views{
    class Entity;
}

namespace controllers{
    class Entity;
}

namespace models {
    class Entity {
    protected:
        std::shared_ptr<views::Entity> m_view;

        std::shared_ptr<controllers::Entity> m_controller;

        std::pair<float, float> m_position;
    public:
        void addView(std::shared_ptr<views::Entity> view);

        void setController(std::shared_ptr<controllers::Entity> controller);

        virtual void update() =0;

        void notify();

        const std::pair<float, float> &position() const;
    };
}

namespace views{
    class Entity : public sf::Drawable{
    protected:
        models::Entity* m_model;
        
    public:
        void setModel(models::Entity *model);

        virtual void update() =0;
    };
}

namespace controllers{
    class Entity{
    protected:
        models::Entity* m_model;

    public:
        void addModel(models::Entity* model);

        virtual void update() =0;

        void notify();

        virtual void handleEvent(const sf::Event& event){};
    };
}


#endif //GRADIUS_ENTITY_H
