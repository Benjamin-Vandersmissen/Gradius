//
// Created by benji on 31/05/18.
//

#ifndef GRADIUS_VIEWS_TEXTENTITY_H
#define GRADIUS_VIEWS_TEXTENTITY_H

#include "Entity.h"
#include "../resources/TextEntity.h"

namespace resources{
    class TextEntity;
}

namespace views {
    class TextEntity : public Entity{
    protected:
        std::shared_ptr<sf::Font> m_font;
    public:
        friend class resources::TextEntity;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    };
}


#endif //GRADIUS_VIEWS_TEXTENTITY_H
