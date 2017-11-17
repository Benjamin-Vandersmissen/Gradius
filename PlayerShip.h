//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_PLAYERSHIP_H
#define GRADIUS_PLAYERSHIP_H

#include "Entity.h"
#include "PlayerBullet.h"
#include "EntityView.h"


namespace entities {
    class PlayerShip : public Entity{
    protected:
        unsigned int m_cooldown = 10;

        unsigned int m_current_cooldown = 0;

        unsigned int m_lives = 3;

        unsigned int m_immunity = 0;

        std::string m_bullet = "";
    public:
        PlayerShip(const std::pair<float, float> &position, const sf::FloatRect &hitbox, float speed, std::string bullet);

        virtual void handleEvent(sf::Event& event);

        //do actions when specific keys are pressed
        void handleKeyboard(sf::Event &event);

        virtual void update();

        void fire();

        virtual void onCollision(Entity *entity);

        unsigned int getLives() const;

        void doDamage(unsigned int damage);

        bool immune();

    };
}

namespace resources {
    class PlayerShip: public EntityResource{
    private:
        sf::Font* m_font;

        std::string m_bullet;
    public:
        PlayerShip();

        entities::PlayerShip* create(const std::pair<float, float>& position);

        void loadFromJson(json j, std::string path);

        void loadFromIni(std::string path, std::string filename);

    };
}

namespace views{
    class PlayerShip : public EntityView{
    private:
        sf::Text m_lives;
        sf::Font* m_font;
    public:
        friend class resources::PlayerShip;

        PlayerShip(entities::Entity *associatedEntity);

        void update();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}


#endif //GRADIUS_PLAYERSHIP_H
