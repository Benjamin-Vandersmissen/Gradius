//
// Created by benji on 31/05/18.
//

#include "TextEntity.h"

model_ptr resources::TextEntity::create(const std::pair<float, float> &position) {
    auto model = std::make_shared<models::TextEntity>();
    model->m_value = m_text;
    auto controller = std::make_shared<controllers::ScrollingEntity>();
    auto view = std::make_shared<views::TextEntity>();
    view->m_font = m_font;

    finalizeCreation(view, model, controller, position);
}

void resources::TextEntity::loadFromIni(const std::string &path, const ini::Configuration &configuration){
    m_text = configuration["Text"]["text"].as_string_or_default("Default String");
    m_fontPath = configuration["Text"]["font"].as_string_or_die();
    m_font = std::make_shared<sf::Font>();
    m_font->loadFromFile(path+m_fontPath);
}
