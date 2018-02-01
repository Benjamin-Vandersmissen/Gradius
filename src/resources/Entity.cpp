//
// Created by benji on 09.12.17.
//

#include "Entity.h"

std::map<std::string, resource_ptr> resources::map = {};

void resources::Entity::loadFromIni(const std::string &path, const ini::Configuration &configuration) {
    std::string texturePath = configuration["General"]["TexturePath"].as_string_or_die();
    unsigned int delay = configuration["General"]["Delay"].as_unsigned_or_default(0);
    unsigned int nrFrames = configuration["General"]["NrFrames"].as_unsigned_or_default(1);
    m_depth = configuration["General"]["Depth"].as_int_or_default(0);
    m_animation = Animation(delay);
    m_animation.createFromStrip(path+texturePath, nrFrames);
    unsigned int textureWidth;
    unsigned int textureHeight;
    if(configuration["General"]["TextureWidth"].as_unsigned_if_exists(textureWidth) && configuration["General"]["TextureHeight"].as_unsigned_if_exists(textureHeight)){
        m_animation.setSize(sf::Vector2u{textureWidth, textureHeight});
    }
    m_hitbox = sf::FloatRect{0,0,Transformation::transformWidth(m_animation.getSize().x), Transformation::transformHeight(m_animation.getSize().y)};
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
    model->depth(m_depth);
    model->notify();

    models::list.insert(models::list.begin(),model);
    views::list.insert(views::list.begin(), view);
    controllers::list.insert(controllers::list.begin(),controller);
}