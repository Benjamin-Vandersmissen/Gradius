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

    notify();

    m_fired = false;

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
    if(isImmune())
        --m_immunity;
    if(myController) {
        if(myController->currentDirection() != std::pair<float, float>{0,0}) {
            m_position.first += m_speed * myController->currentDirection().first;
            m_position.second += m_speed * myController->currentDirection().second;
            clamp(m_position.first,Transformation::left(), Transformation::left()+Transformation::width() - m_hitbox.width);
            clamp(m_position.second,Transformation::top(), Transformation::top()+Transformation::height() - m_hitbox.height);
            notify();
        }
        if(myController->fired()){
            try {
                resources::map.at(m_bulletType)->create(
                        std::pair<float,float>{m_position.first + m_hitbox.width / 2, m_position.second + m_hitbox.height / 2});
            }catch(std::exception){
                throw ResourceException(ResourceException::missingResource, m_bulletType);
            }
        }
    }
}


void models::PlayerShip::dealDamage(unsigned int damage) {
    if(isImmune())
        return;
    if(damage < m_lives){
        m_lives -= damage;
        m_immunity = m_maxImmunity;
        notify();
    }
    else{
        m_lives = 0;
    }
}

unsigned int models::PlayerShip::lives() const {
    return m_lives;
}

bool models::PlayerShip::isImmune() const {
    return m_immunity != 0;
}

void views::PlayerShip::update() {
    auto model = dynamic_cast<models::PlayerShip*>(m_model);
    if(model){
        m_text.setString("Lives "+ std::to_string(model->lives()));
        if(model->isImmune())
            m_animation.setColor(sf::Color{127,127,127});
        else
            m_animation.setColor(sf::Color{255,255,255});
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
    m_text.setPosition(Transformation::invTransform(std::pair<float,float>{-3.9,-2.9}));
    m_text.setScale(0.25,0.25);
}

model_ptr resources::PlayerShip::create(const std::pair<float, float> &position) {
    auto model = std::make_shared<models::PlayerShip>();
    model->m_speed = m_speed;
    model->m_bulletType = m_bulletType;
    model->hitbox(m_hitbox);

    auto view = std::make_shared<views::PlayerShip>();
    view->m_font = m_font;
    view->initText();
    auto controller = std::make_shared<controllers::PlayerShip>();
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
