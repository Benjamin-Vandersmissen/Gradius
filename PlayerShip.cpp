//
// Created by benji on 13.11.17.
//

#include <iostream>
#include "PlayerShip.h"
#include "EnemyShip.h"
#include "BorderObstacle.h"

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
    if(m_position.first + desiredDirection.first + m_hitbox.left + m_hitbox.width > Transformation::left()+Transformation::width())
        desiredDirection.first = 0;
    if(m_position.first + desiredDirection.first + m_hitbox.left < Transformation::left())
        desiredDirection.first = 0;
    if(m_position.second + desiredDirection.second + m_hitbox.top < Transformation::top())
        desiredDirection.second = 0;
    if(m_position.second + desiredDirection.second + m_hitbox.top + m_hitbox.height > Transformation::top() + Transformation::height()){
        desiredDirection.second = 0;
    }
    m_direction = desiredDirection;
    Entity::update();
    if(m_current_cooldown > 0)
        m_current_cooldown--;
    if(m_immunity > 0)
        m_immunity--;
}

void entities::PlayerShip::fire() {
    if (m_current_cooldown == 0) {
        resources::resourceMap[m_bullet]->create({this->m_position.first+this->m_hitbox.width/2, this->m_position.second+this->m_hitbox.height/2});
        m_current_cooldown = m_cooldown;
    }
}

void entities::PlayerShip::onCollision(Entity *entity) {
    EnemyShip* enemyShip = dynamic_cast<EnemyShip*>(entity);
    if(enemyShip){
        this->doDamage(1);
        enemyShip->markDeleted();
    }
    BorderObstacle* borderObstacle = dynamic_cast<BorderObstacle*>(entity);
    if(borderObstacle){
        this->doDamage(2);
    }
    else{ //borderObstacle is a subclass of Obstacle, this will ensure the collision will only be counted once
        Obstacle* obstacle = dynamic_cast<Obstacle*>(entity);
        if(obstacle) {
            this->doDamage(1);
            obstacle->markDeleted();
        }
    }

}

unsigned int entities::PlayerShip::getLives() const{
    return m_lives;
}

entities::PlayerShip::PlayerShip(const std::pair<float, float> &position, const sf::FloatRect &hitbox, float speed, std::string bullet)
        : Entity(
        position, hitbox, speed) {
    m_bullet = bullet;
}

void entities::PlayerShip::doDamage(unsigned int damage) {
    if(m_immunity > 0){
        return;
    }
    if(damage > m_lives){
        //DED
    }
    else{
        m_lives -= damage;
        m_immunity = 100;
    }
}

bool entities::PlayerShip::immune() {
    return m_immunity > 0;
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
    entities::PlayerShip* ship = dynamic_cast<entities::PlayerShip*>(m_associatedEntity);
    if(ship){
        m_lives.setString("lives " + std::to_string(ship->getLives()));
        if(ship->immune()){
            m_sprite.setColor({192,192,192,128});
        }
        else{
            m_sprite.setColor({255,255,255});
        }
        EntityView::update();
    }
}

void views::PlayerShip::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    EntityView::draw(target, states);
    target.draw(m_lives, states);
}

entities::PlayerShip *resources::PlayerShip::create(const std::pair<float, float> &position) {
    entities::PlayerShip* entity = new entities::PlayerShip(position, m_hitbox, m_speed, m_bullet);
    views::PlayerShip* view = new views::PlayerShip(entity);
    view->m_texture = m_texture;
    view->loadSprite();
    view->m_font = m_font;
    views::viewList.push_back(view);
    entities::entityList.push_back(entity);
    return entity;
}

void resources::PlayerShip::loadFromJson(json j, std::string path) {
    EntityResource::loadFromJson(j, path);
    std::string fontPath = j["FontPath"];
    this->m_font = new sf::Font;
    this->m_font->loadFromFile(path+fontPath);

    this->m_bullet = j["BulletType"];
}

resources::PlayerShip::PlayerShip() {}

void resources::PlayerShip::loadFromIni(std::string path, std::string filename) {
    EntityResource::loadFromIni(path, filename);
    std::ifstream stream(path+filename);
    ini::Configuration configuration(stream);
    std::string fontPath = configuration["PlayerShip"]["FontPath"].as_string_or_die();
    this->m_font = new sf::Font;
    this->m_font->loadFromFile(path+fontPath);

    this->m_bullet = configuration["PlayerShip"]["BulletType"].as_string_or_default("PlayerBullet");
}
