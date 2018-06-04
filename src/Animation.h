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
    /**
     * @brief create an empty animation
     * */
    Animation();

    /**
     * @brief create an animation with a specific delay
     * */
    explicit Animation(int m_delay);

    /**
     * @brief create an animation with a set of frames and a delay
     * */
    Animation(const std::vector<sf::Sprite> &m_sprites, int m_delay);

    /**
     * @brief add a frame to the animation
     * */
    void addSprite(const sf::Sprite& sprite);

    /**
     * @brief update the internal timer, and if necessary change the current frame
     * */
    void update();

    /**
     * @brief overload of SFML draw function
     * */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    /**
     * @brief create a strip animation from a file, with a specified amount of frames
     * */
    void createFromStrip(std::string filename, unsigned int amount);

    /**
     * @brief set a modulated color for all frames
     * */
    void setColor(const sf::Color& color);

    /**
     * @brief return the size of a frame
     * */
    sf::Vector2u getSize() const;

    /**
     * @brief set the size of all frames
     * */
    void setSize(const sf::Vector2u &size);

    /**
     * @brief set the delay between two frames
     * */
    void setDelay(unsigned int delay);
};


#endif //GRADIUS_ANIMATION_H
