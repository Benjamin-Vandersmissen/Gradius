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
        markDeleted();
    }
    m_sprite.setPosition(Transformation::invTransform(m_associatedEntity->getPosition()));
}

void views::EntityView::loadSprite() {
    m_sprite = sf::Sprite();
    m_sprite.setTexture(*m_texture);
}

void views::EntityView::markDeleted() {
    m_deleted = true;
}

bool views::EntityView::deleted() {
    return m_deleted;
}

void views::deleteMarkedViews() {
    for(auto it = EntityView::viewList.begin(); it < EntityView::viewList.end(); ++it){
        if((*it)->deleted()){
            delete *it;
            it = EntityView::viewList.erase(it);
        }
    }
}