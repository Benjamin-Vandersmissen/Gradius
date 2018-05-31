//
// Created by benji on 31/05/18.
//

#include "TextEntity.h"

void views::TextEntity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    auto model = std::dynamic_pointer_cast<models::TextEntity>(m_model);
    std::string value = model->text();
    sf::Text text{value, *m_font};
    text.setScale(0.5,0.5);
    text.setPosition(Transformation::invTransform(model->position()));
    target.draw(text, states);
}
