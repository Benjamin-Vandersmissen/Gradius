//
// Created by benji on 09.12.17.
//

#include "Entity.h"

std::map<std::string, resource_ptr> resources::map = {};

void resources::Entity::loadFromIni(const std::string &path, const ini::Configuration &configuration) {
    unsigned int delay = configuration["General"]["Delay"].as_unsigned_or_default(0);
    unsigned int nrFrames = configuration["General"]["NrFrames"].as_unsigned_or_default(1);
    m_depth = configuration["General"]["Depth"].as_int_or_default(0);
    m_animation = Animation(delay);
    std::string texturePath;
    if (configuration["General"]["TexturePath"].as_string_if_exists(texturePath)){
        m_animation.createFromStrip(path+texturePath, nrFrames);
    }
    unsigned int textureWidth;
    unsigned int textureHeight;
    if(configuration["General"]["TextureWidth"].as_unsigned_if_exists(textureWidth) && configuration["General"]["TextureHeight"].as_unsigned_if_exists(textureHeight)){
        m_animation.setSize(sf::Vector2u{textureWidth, textureHeight});
    }
    createHitbox(configuration);
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

    model->hitbox(m_hitbox);

    models::list.insert(models::list.begin(),model);
    views::list.insert(views::list.begin(), view);
    controllers::list.insert(controllers::list.begin(),controller);
}

void resources::Entity::createHitbox(const ini::Configuration &config) {
    std::string representation;
    if(!config["General"]["Hitbox"].as_string_if_exists(representation)){ //no custom hitbox found, make from default texture
        auto size = m_animation.getSize();
        m_hitbox.addPoint({0,0});
        m_hitbox.addPoint({Transformation::transformWidth(size.x),0});
        m_hitbox.addPoint({Transformation::transformWidth(size.x),Transformation::transformHeight(size.y)});
        m_hitbox.addPoint({0,Transformation::transformHeight(size.y)});
        return;
    }
    else{
        std::string number;
        bool number1 = false;
        bool number2 = false;
        bool started = false;
        sf::Vector2u point;
        for(char c : representation){
            if(!started && !number1 && !number2 && c == '{')
                started = true;
            else if(!number1 && !number2 && c == '('){
               number1 = true;
            }
            else if((number1 || number2) && isdigit(c))
                number += c;
            else if(number1 && c == ',') {
                number1 = false;
                number2 = true;
                point.x = static_cast<unsigned>(std::stoi(number));
                number = "";
            }
            else if(number2 && c ==')'){
                number2 = false;
                point.y = static_cast<unsigned>(std::stoi(number));
                number = "";
                sf::Vector2f transformedPoint = {Transformation::transformWidth(point.x), Transformation::transformWidth(point.y)};
                m_hitbox.addPoint(transformedPoint);
            }
            else if(!number2 && (c == ',' || c == ' '))
                continue;
            else if(!number1 && !number2 && c == '}'){
                started = false;
            }
            else{
                throw ResourceException(ResourceException::malformedInput, "test", "Hitbox");
            }
        }
    }
}
