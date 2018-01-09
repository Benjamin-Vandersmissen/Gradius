//
// Created by uauser on 12/14/17.
//

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

    m_defaultFont = std::make_shared<sf::Font>();
    m_defaultFont->loadFromFile("../resources/fonts/ARCADECLASSIC.TTF");

    float size = 0.04f/Transformation::width()*Transformation::windowWidth();
    m_menuSelector = sf::CircleShape(size, 3);
    m_menuSelector.setFillColor(sf::Color::Red);
    m_menuSelector.setOrigin(size, size);
    m_menuSelector.setRotation(-30);
}

std::shared_ptr<sf::RenderWindow> views::View::window() const {
    return m_window;
}

void views::View::draw() {
    m_window->clear();
    switch(m_model->gameState()) {
        case models::Model::Running :{
            for (const auto &view : views::list) {
                view->updateAnimation();
                m_window->draw(*view);
            }
            break;
        }
        case models::Model::PauseMenu:{
            for(const auto& view : views::list){
                m_window->draw(*view);
            }
            drawMenu();
            break;
        }
        case models::Model::MainMenu :{
            drawMenu();
            break;
        }
        case models::Model::LoadLevelMenu :{
            sf::Text text;
            if(m_model->tempLevel().empty()){
                text.setString("Type Something");
                text.setColor(sf::Color::Red);
            }
            else{
                text.setString(m_model->tempLevel());
                text.setColor(sf::Color::Cyan);
            }
            text.setFont(*m_defaultFont);
            text.setScale({1.0f/3.0f,1.0f/3.0f});
            text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);
            text.setPosition(Transformation::invTransform({0,-1.5f}));
            sf::Text text2("Level", *m_defaultFont);
            text2.setScale({1.0f/3.0f,1.0f/3.0f});
            text2.setOrigin(text2.getLocalBounds().width/2, text2.getLocalBounds().height/2);
            text2.setPosition(Transformation::invTransform({0,-2.0f}));
            m_window->draw(text);
            m_window->draw(text2);
            drawMenu();
            break;
        }
        case models::Model::GameWon :{
            sf::Text text;
            text.setString("You    Won");
            text.setFont(*m_defaultFont);
            text.setScale({2.0f/3.0f, 2.0f/3.0f});
            text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);
            text.setPosition(Transformation::invTransform({0,-1.5f}));
            m_window->draw(text);
            drawMenu();
            break;
        }
        case models::Model::GameLost :{
            sf::Text text;
            text.setString("You    Lost");
            text.setFont(*m_defaultFont);
            text.setScale({2.0f/3.0f, 2.0f/3.0f});
            text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);
            text.setPosition(Transformation::invTransform({0,-1.5f}));
            m_window->draw(text);
            drawMenu();
            break;
        }
    }
    m_window->display();
}

void views::View::drawMenu() {
    for(const models::menuObject& obj : m_model->getMenu()){
        sf::Text text(obj.string, *m_defaultFont);
        text.setScale({1.0f/3.0f,1.0f/3.0f});
        text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);
        text.setPosition(Transformation::invTransform({obj.xPosition, obj.yPosition}));
        if(obj.menuState == m_model->currentMenuObject().menuState){
            sf::Vector2f position = {text.getGlobalBounds().left-m_menuSelector.getRadius(), text.getGlobalBounds().top + text.getGlobalBounds().height/2};
            m_menuSelector.setPosition(position);
        }
        m_window->draw(text);
    }
    m_window->draw(m_menuSelector);
}
