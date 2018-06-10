//
// Created by benji on 10/06/18.
//

#ifndef GRADIUS_SPRITE_H
#define GRADIUS_SPRITE_H

#include <SFML/Graphics.hpp>
#include "BaseSprite.h"

class BaseSprite;

class Sprite : public sf::Drawable, public sf::Transformable{
private:
    std::vector<sf::Sprite> m_sprites;

    unsigned int m_delay = 0;

    unsigned int m_currentDelay = 0;

    std::size_t m_index = 0;
public:

    friend class BaseSprite;

    /**
     * @brief overwrites the default draw method from SFML
     * */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override ;

    void update();

    bool valid() const;

    void setColor(const sf::Color& color);

    sf::Vector2u getSize() const;
};


#endif //GRADIUS_SPRITE_H
