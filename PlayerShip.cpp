//
// Created by benji on 22.11.17.
//

#include <iostream>
#include "PlayerShip.h"
#include "PlayerBullet.h"

void controllers::PlayerShip::update() {
    float dx = sf::Keyboard::isKeyPressed(sf::Keyboard::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    float dy = sf::Keyboard::isKeyPressed(sf::Keyboard::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    m_currentDirection = {dx,dy};

    if(m_currentDirection != std::pair<float,float>{0,0}){
        notify();
    }
    if(m_fired){
        notify();
        m_fired = false;
    }
    if(m_fireCooldown > 0){
        m_fireCooldown--;
    }
}

const std::pair<float, float> &controllers::PlayerShip::currentDirection() const {
    return m_currentDirection;
}

void controllers::PlayerShip::handleEvent(const sf::Event &event) {
    switch(event.type){
        case sf::Event::KeyPressed:{
            switch(event.key.code){
                case sf::Keyboard::Space:{
                    if(m_fireCooldown == 0){
                        m_fireCooldown = m_maxFireCooldown;
                        m_fired = true;
                    }
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

bool controllers::PlayerShip::fired() {
    return m_fired;
}

void models::PlayerShip::update() {
    auto myController = dynamic_cast<controllers::PlayerShip*>(m_controller);
    if(myController) {
        if(myController->currentDirection() != std::pair<float, float>{0,0}) {
            m_position.first += m_speed * myController->currentDirection().first;
            m_position.second += m_speed * myController->currentDirection().second;
            clamp(m_position.first,Transformation::left(), Transformation::left()+Transformation::width() - m_hitbox.width);
            clamp(m_position.second,Transformation::top(), Transformation::top()+Transformation::height() - m_hitbox.height);
            notify();
        }
        if(myController->fired()){
            resources::map[m_bulletType]->create({m_position.first+m_hitbox.width/2, m_position.second+m_hitbox.height/2});
        }
    }
}


void models::PlayerShip::dealDamage(unsigned int damage) {
    if(damage < m_lives){
        m_lives -= damage;
        notify();
    }
    else{
        m_lives = 0;
    }
}

unsigned int models::PlayerShip::lives() const {
    return m_lives;
}

void views::PlayerShip::update() {
    auto model = dynamic_cast<models::PlayerShip*>(m_model);
    if(model){
        m_text.setString("Lives "+ std::to_string(model->lives()));

    }
    Entity::update();
}

void views::PlayerShip::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    Entity::draw(target, states);
    target.draw(m_text);
}

void views::PlayerShip::initText() {
    m_text = sf::Text();
    m_text.setFont(*m_font);
    m_text.setColor(sf::Color::Cyan);
    m_text.setOrigin(0,0);
    m_text.setPosition(Transformation::invTransform({-3.9,-2.9}));
    m_text.setScale(0.25,0.25);
}

models::PlayerShip *resources::PlayerShip::create(const std::pair<float, float> &position) {
    auto model = new models::PlayerShip;
    model->m_speed = m_speed;
    model->m_bulletType = m_bulletType;
    model->hitbox(m_hitbox);

    auto view = new views::PlayerShip;
    view->m_font = m_font;
    view->initText();
    auto controller = new controllers::PlayerShip;
    finalizeCreation(view, model, controller, position);
    return model;
}

void resources::PlayerShip::loadFromIni(std::string path, ini::Configuration &configuration) {
    Entity::loadFromIni(path, configuration);
    m_speed = configuration["General"]["Speed"].as_double_or_die();
    m_bulletType = configuration["PlayerShip"]["BulletType"].as_string_or_default("PlayerBullet");
    std::string fontPath = path + configuration["PlayerShip"]["FontPath"].as_string_or_die();
    m_font = std::make_shared<sf::Font>();
    m_font->loadFromFile(fontPath);
}

void clamp(float &value, float lo, float hi) {
    if(value < lo){
        value = lo;
    }
    if(value > hi)
        value = hi;
}
