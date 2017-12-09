//
// Created by benji on 09.12.17.
//

#include "Entity.h"

std::map<std::string, resources::Entity*> resources::map = {};

void resources::Entity::loadFromIni(std::string path, ini::Configuration &configuration) {
    std::string texturePath = configuration["General"]["TexturePath"].as_string_or_die();
    int delay = configuration["General"]["Delay"].as_int_or_default(-1);
    unsigned int nrFrames = configuration["General"]["NrFrames"].as_int_or_default(1);
    m_animation = Animation(delay);
    m_animation.createFromStrip(path+texturePath, nrFrames);
    std::pair<float, float> size = Transformation::transform(m_animation.getSize().x, m_animation.getSize().y);
    m_hitbox = sf::FloatRect{0,0,size.first-Transformation::left(), size.second-Transformation::top()};
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