//
// Created by uauser on 12/14/17.
//

#include <iostream>
#include "View.h"

void views::View::setModel(std::shared_ptr<models::Model> model) {
    m_model = model;
    model->addView(shared_from_this());
    update();
}

void views::View::update() {
    if(m_model->exit()){
        m_window->close();
    }
}

views::View::View(unsigned int width, unsigned int height, const std::string &title) {
    m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(200,150), title);
    m_window->setSize({width, height});
    Transformation::initTransformation(width, height);
}

std::shared_ptr<sf::RenderWindow> views::View::window() const {
    return m_window;
}
