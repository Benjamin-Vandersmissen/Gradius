//
// Created by benji on 22.11.17.
//

#include "Entity.h"

std::list<model_ptr> models::list = {};

void ::models::deleteMarkedEntities() {
    bool deletedItems = false;
    for(auto it = list.begin(); it != list.end(); ++it){
        if((*it)->deleted()){
            deletedItems = true;
            it = list.erase(it);
        }
    }
    if(!deletedItems)
        return;
    for(auto it = views::list.begin(); it != views::list.end(); ++it){
        if((*it)->deleted()){
            it = views::list.erase(it);
        }
    }
    for(auto it = controllers::list.begin(); it != controllers::list.end(); ++it){
        if((*it)->deleted()){
            it = controllers::list.erase(it);
        }
    }
}

std::list<view_ptr> views::list = {};

std::list<controller_ptr> controllers::list = {};

void models::Entity::addView(views::Entity *view) {
    m_view = view;
}

void models::Entity::setController(controller_ptr controller) {
    m_controller = controller;
    controller->addModel(shared_from_this());
}

void models::Entity::notify() {
    m_view->update();
}

const std::pair<float, float> &models::Entity::position() const {
    return m_position;
}

void models::Entity::position(const std::pair<float, float> &position) {
    m_position.first = position.first;
    m_position.second = position.second;
}

model_ptr models::Entity::collision() {
    for(model_ptr entity: models::list){
        if(entity->globalHitbox().intersects(this->globalHitbox()) && entity.get() != this){
            return entity;
        }
    }
    return nullptr;
}

sf::FloatRect models::Entity::globalHitbox() {
    return {m_hitbox.left+m_position.first, m_hitbox.top+m_position.second, m_hitbox.width, m_hitbox.height};
}

void models::Entity::hitbox(const sf::FloatRect hitbox) {
    m_hitbox = hitbox;
}

bool models::Entity::deleted() const {
    return m_deleted;
}

void models::Entity::markDeleted() {
    m_deleted = true;
    m_view->markDeleted();
    m_controller->markDeleted();
}


void controllers::Entity::addModel(model_ptr model) {
    m_model = model;
}

void controllers::Entity::notify() {
    m_model->update();
}

bool controllers::Entity::deleted() const {
    return m_deleted;
}

void views::Entity::setModel(model_ptr model) {
    m_model = model;
    model->addView(this);
    model->notify();
}

void views::Entity::update() {
    m_animation.setPosition(Transformation::invTransform(m_model->position()));

}

void resources::Entity::loadFromIni(std::string path, ini::Configuration &configuration) {
    std::string texturePath = configuration["General"]["TexturePath"].as_string_or_die();
    int delay = configuration["General"]["Delay"].as_int_or_default(-1);
    unsigned int nrFrames = configuration["General"]["NrFrames"].as_int_or_default(1);
    m_animation = Animation(delay);
    m_animation.createFromStrip(path+texturePath, nrFrames);
    std::pair<float, float> size = Transformation::transform(m_animation.getSize().x, m_animation.getSize().y);
    m_hitbox = sf::FloatRect{0,0,size.first-Transformation::left(), size.second-Transformation::top()};
}

bool views::Entity::deleted() const {
    return m_deleted;
}

void views::Entity::updateAnimation() {
    m_animation.update();
}

void resources::Entity::setAnimationOfView(view_ptr view) {
    view->m_animation = m_animation;
}

void resources::Entity::finalizeCreation(view_ptr view, model_ptr model, controller_ptr controller,
                                         std::pair<float, float> position) {
    model->setController(controller);
    view->setModel(model);
    setAnimationOfView(view);

    model->position(position);
    model->notify();

    models::list.insert(models::list.begin(),model);
    views::list.insert(views::list.begin(), view);
    controllers::list.insert(controllers::list.begin(),controller);
}

std::map<std::string, resources::Entity*> resources::map = {};