//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_ENTITYVIEW_H
#define GRADIUS_ENTITYVIEW_H

#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Animation.h"

namespace views {
    class EntityView : public sf::Drawable{
    protected:

        Animation* m_animation;

        entities::Entity* m_associatedEntity;

        bool m_deleted = false;
    public:
        EntityView(entities::Entity *associatedEntity);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        virtual void update();

        void markDeleted();

        bool deleted();

        friend void deleteMarkedViews();
    };
    extern std::vector<views::EntityView*> viewList;

    void deleteMarkedViews();
}


#endif //GRADIUS_ENTITYVIEW_H
