//
// Created by benji on 09.12.17.
//

#include "Ship.h"

void views::Ship::update() {
    auto model = std::dynamic_pointer_cast<models::Ship>(m_model);
    if(model){
        if(model->isImmune())
            m_sprite.setColor(sf::Color{127,127,127});
        else
            m_sprite.setColor(sf::Color{255,255,255});
    }
    Entity::update();
}

void views::Ship::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    Entity::draw(target, states);
    auto model = std::dynamic_pointer_cast<models::Ship>(m_model);
    if(model){
        for(unsigned int i = 0; i < model->lives(); i++){
            sf::Sprite heart{*m_heartTexture};
            sf::FloatRect bounds = model->globalHitbox().bounds();
            heart.setPosition(Transformation::invTransform({bounds.left+Transformation::transformWidth(heart.getGlobalBounds().width)*i, bounds.top-Transformation::transformHeight(heart.getGlobalBounds().height)}));
            target.draw(heart);
        }
    }
}
