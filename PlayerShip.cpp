//
// Created by benji on 13.11.17.
//

#include <iostream>
#include "PlayerShip.h"
#include "EnemyShip.h"

void entities::PlayerShip::handleEvent(sf::Event &event) {
    switch(event.type) {
        case sf::Event::KeyPressed:
            handleKeyboard(event);
        default:
            break;
    }
}

void entities::PlayerShip::handleKeyboard(sf::Event &event) {
    switch(event.key.code){
        case sf::Keyboard::Space:
            fire();
            break;

        default:
            break;
    }
}


void entities::PlayerShip::update() {
    bool keyUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    bool keyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    bool keyRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    bool keyLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);

    std::pair<double, double> desiredDirection = {m_speed*(keyRight-keyLeft), m_speed*(keyDown-keyUp)};

//    m_direction = {(m_direction.first + desiredDirection.first)/2, (m_direction.second + desiredDirection.second)/2};
    m_direction = desiredDirection;
    Entity::update();
    if(m_current_cooldown > 0)
        m_current_cooldown--;
}

entities::PlayerShip::PlayerShip(const std::pair<float, float> &position, sf::Texture *texture, float speed) : Entity(
        position, texture, speed) {
    bulletTexture = new sf::Texture();
    bulletTexture->loadFromFile("../NES - Gradius - Gradius.png", {51,154,8,4});
}

void entities::PlayerShip::fire() {
    if (m_current_cooldown == 0) {
        entityList.insert(entityList.begin(),
                new PlayerBullet({this->m_position.first, this->m_position.second}, bulletTexture, 0.15));
        m_current_cooldown = m_cooldown;
    }
}

void entities::PlayerShip::onCollision(Entity *entity) {
    EnemyShip* enemyShip = dynamic_cast<EnemyShip*>(entity);
    if(enemyShip){
        this->m_lives--;
        enemyShip->markDeleted();
    }
}

unsigned int entities::PlayerShip::getLives() const{
    return m_lives;
}

views::PlayerShip::PlayerShip(entities::Entity *associatedEntity) : EntityView(associatedEntity){
    m_font = new sf::Font();
    m_font->loadFromFile("../fonts/ARCADECLASSIC.TTF");

    m_lives = sf::Text();
    m_lives.setFont(*m_font);
    m_lives.setScale(0.25,0.25);
    m_lives.setColor(sf::Color::Cyan);
    m_lives.setPosition(Transformation::invTransform({-3.75,-2.75}));

    m_texture = new sf::Texture();
    m_texture->loadFromFile("../NES - Gradius - Gradius.png", {0,100,32,16});
    m_sprite = sf::Sprite();
    m_sprite.setTexture(*m_texture);
}

void views::PlayerShip::update() {
    EntityView::update();
    entities::PlayerShip* ship = dynamic_cast<entities::PlayerShip*>(m_associatedEntity);
    if(ship){
        m_lives.setString("lives " + std::to_string(ship->getLives()));
    }
}

void views::PlayerShip::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    EntityView::draw(target, states);
    target.draw(m_lives, states);
}
