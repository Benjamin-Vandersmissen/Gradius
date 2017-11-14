//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_ENTITYVIEW_H
#define GRADIUS_ENTITYVIEW_H

#include "SFML/Graphics.hpp"
#include "Entity.h"

namespace views {
    class EntityView : public sf::Drawable{
    protected:
        sf::Sprite m_sprite;

        entities::Entity* m_associatedEntity;
    public:
        EntityView(entities::Entity *associatedEntity);

        ~EntityView();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        virtual void update();

        static std::vector<views::EntityView*> viewList;

        void destroy();
    };
}


#endif //GRADIUS_ENTITYVIEW_H
