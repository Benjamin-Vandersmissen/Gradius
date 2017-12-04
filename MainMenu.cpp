//
// Created by uauser on 11/30/17.
//

#include "MainMenu.h"

void controllers::MainMenu::update() {
    if(m_direction != 0){
        notify();
        m_direction = 0;
    }
}

void controllers::MainMenu::handleEvent(const sf::Event &event) {
    switch(event.type){
        case sf::Event::KeyPressed:{
            switch(event.key.code){
                case sf::Keyboard::W:{
                    m_direction--;
                    break;
                }
                case sf::Keyboard::S:{
                    m_direction++;
                    break;
                }
                default:{
                    break;
                }
            }
            break;
        }
        default:{
            break;
        }
    }
}

int controllers::MainMenu::direction() {
    return m_direction;
}

void models::MainMenu::update() {
    auto controller = std::dynamic_pointer_cast<controllers::MainMenu>(m_controller);
    m_selectedState = (m_selectedState + controller->direction() + states::END) % states::END;
    std::cout << m_selectedState << std::endl;
}
