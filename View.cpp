//
// Created by benji on 22.11.17.
//

#include "View.h"

void views::View::update() {
    m_window->clear();
    m_window->draw(*this);
    m_window->display();
}

void views::View::setModel(models::Model *model) {
    m_model = model;
    std::cout << "Model " << model << " set in View " << this << std::endl;
    model->addView(std::shared_ptr<views::View>(this));
}

views::View::View(unsigned int width, unsigned int height) {
    m_window = new sf::RenderWindow(sf::VideoMode(width, height), "Gradius ~ Test");
}

void views::View::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}

sf::RenderWindow * views::View::window() {
    return m_window;
}