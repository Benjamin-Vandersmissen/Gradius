//
// Created by benji on 13.11.17.
//

#include "EntityView.h"

std::vector<views::EntityView*> views::EntityView::viewList = {};

void views::EntityView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(m_sprite, states);
}

views::EntityView::EntityView(entities::Entity *associatedEntity) : m_associatedEntity(associatedEntity) {}

void views::EntityView::update() {
    if(m_associatedEntity->deleted()){
        destroy();
    }
    m_sprite.setPosition(Transformation::invTransform(m_associatedEntity->getPosition()));
}

void views::EntityView::destroy() {
    viewList.erase(std::find(viewList.begin(), viewList.end(), this));
    delete this;
}

views::EntityView::~EntityView() {
    m_associatedEntity->destroy();
}

void views::EntityView::loadSprite() {
    m_sprite = sf::Sprite();
    m_sprite.setTexture(*m_texture);
}
