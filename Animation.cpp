//
// Created by benji on 19.11.17.
//

#include "Animation.h"

Animation::Animation(int m_delay) : m_delay(m_delay), m_current_delay(m_delay){
}

void Animation::addSprite(const sf::Sprite &sprite) {
    m_sprites.push_back(sprite);
}

Animation::Animation(const std::vector<sf::Sprite> &m_sprites, int m_delay) : m_sprites(m_sprites), m_delay(m_delay), m_current_delay(m_delay) {}

void Animation::update() {
    if(m_delay > 0) {
        m_current_delay = (m_current_delay + 1) % m_delay;
    }
    if(m_current_delay == 0){
        m_index = (m_index + 1) % m_sprites.size();
    }
}

void Animation::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(m_sprites[m_index], states);
}

void Animation::createFromStrip(std::string filename, unsigned int amount) {
    m_texture = new sf::Texture;
    m_texture->loadFromFile(filename);
    unsigned int width = m_texture->getSize().x/amount;
    for(unsigned int i = 0; i < m_texture->getSize().x; i += width){
        m_sprites.push_back(sf::Sprite(*m_texture, sf::IntRect(i,0,width,m_texture->getSize().y)));
    }
}

void Animation::setColor(const sf::Color &color) {
    for(sf::Sprite& sprite : m_sprites){
        sprite.setColor(color);
    }
}

sf::Vector2u Animation::getSize() {
    return {m_texture->getSize().x/m_sprites.size(), m_texture->getSize().y};
}

Animation::Animation() {}
