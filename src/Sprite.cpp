//
// Created by benji on 10/06/18.
//

#include "Sprite.h"
void Sprite::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(m_sprites[m_index], states);
}

bool Sprite::valid() const {
    return !m_sprites.empty();
}

void Sprite::update() {
    if(m_sprites.empty())
        return;
    if(m_delay > 0) {
        m_currentDelay = (m_currentDelay + 1) % m_delay;
    }
    if(m_currentDelay == 0){
        m_index = (m_index + 1) % m_sprites.size();
    }
}

void Sprite::setColor(const sf::Color &color) {
    for(auto& sprite : m_sprites){
        sprite.setColor(color);
    }
}

sf::Vector2u Sprite::getSize() const {
    if(m_sprites.empty())
        return {0,0};
    return {m_sprites[0].getLocalBounds().width, m_sprites[0].getLocalBounds().height};
}
