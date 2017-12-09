//
// Created by benji on 09.12.17.
//

#include "PlayerShip.h"

void views::PlayerShip::update() {
    auto model = std::dynamic_pointer_cast<models::PlayerShip>(m_model);
    if(model){
        m_text.setString("Lives "+ std::to_string(model->lives()));
        if(model->isImmune())
            m_animation.setColor(sf::Color{127,127,127});
        else
            m_animation.setColor(sf::Color{255,255,255});
    }
    Entity::update();
}

void views::PlayerShip::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    Entity::draw(target, states);
    target.draw(m_text);
}

void views::PlayerShip::initText() {
    m_text = sf::Text();
    m_text.setFont(*m_font);
    m_text.setColor(sf::Color::Cyan);
    m_text.setOrigin(0,0);
    m_text.setPosition(Transformation::invTransform(std::pair<float,float>{-3.9,-2.9}));
    m_text.setScale(0.25,0.25);
}