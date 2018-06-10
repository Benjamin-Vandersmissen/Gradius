//
// Created by benji on 09.12.17.
//

#include "Entity.h"

std::multiset<view_ptr, views::viewCmpt>views::list = {};

void views::Entity::setModel(model_ptr model) {
    m_model = model;
    model->addView(shared_from_this());
    update();
}

void views::Entity::update() {
    m_sprite.setPosition(Transformation::invTransform(m_model->position()));
}

bool views::Entity::deleted() const {
    return m_deleted;
}

void views::Entity::updateSprite() {
    m_sprite.update();
}

void views::Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(m_sprite, states);

//
//    The following code draws the bounding box and the hitbox for the entity
//
//    auto box = m_model->globalHitbox();
//    sf::RectangleShape a({box.getGraphicRepresentation().getGlobalBounds().width, box.getGraphicRepresentation().getGlobalBounds().height});
//    a.setPosition({box.getGraphicRepresentation().getGlobalBounds().left, box.getGraphicRepresentation().getGlobalBounds().top});
//    a.setFillColor(sf::Color::Red);
//    target.draw(a);
//    target.draw(box.getGraphicRepresentation());
}

bool views::viewCmpt::operator()(const view_ptr &lhs, const view_ptr &rhs) {
    return lhs->m_model->depth() < rhs->m_model->depth();
}
