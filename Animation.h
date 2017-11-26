//
// Created by benji on 19.11.17.
//

#ifndef GRADIUS_ANIMATION_H
#define GRADIUS_ANIMATION_H

#include "SFML/Graphics.hpp"
#include <memory>

class Animation : public sf::Transformable, public sf::Drawable{
private:
    std::vector<sf::Sprite> m_sprites;
    std::shared_ptr<sf::Texture> m_texture;
    std::size_t m_index = 0;
    int m_delay;
    int m_current_delay;
public:
    Animation();

    explicit Animation(int m_delay);
    
    Animation(const std::vector<sf::Sprite> &m_sprites, int m_delay);

    void addSprite(const sf::Sprite& sprite);

    void update();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void createFromStrip(std::string filename, unsigned int amount);

    void setColor(const sf::Color& color);

    sf::Vector2u getSize() const;

    void setDelay(unsigned int delay);
};


#endif //GRADIUS_ANIMATION_H
