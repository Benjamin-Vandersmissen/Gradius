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
        //the amount of cooldown after firing (in game ticks)
        unsigned int m_cooldown = 10;

        //the current cooldown
        unsigned int m_current_cooldown = 0;

        //the current amount of lives
        unsigned int m_lives = 3;

        //the current duration of immunity (in game ticks)
        unsigned int m_immunity = 0;

        //the type of bullet that will be fired
        std::string m_bullet = "";
    public:
        PlayerShip(const std::pair<float, float> &position, const sf::FloatRect &hitbox, float speed, std::string bullet);

        virtual void handleEvent(sf::Event& event);

        //do actions when specific keys are pressed
        void handleKeyboard(sf::Event &event);

        virtual void update();
        /**
         * \brief create a bullet of type m_bullet and trigger a cooldown period
         * */
        void fire();

        virtual void onCollision(Entity *entity);

        /**
         * \brief return the current amount of lives
         * */
        unsigned int getLives() const;

        /**
         * \brief substract \param damage from the lives and trigger a immunity period
         * */
        void doDamage(unsigned int damage);

        /**
         * \brief return wether the Playership is immune or not
         * */
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

        std::shared_ptr<entities::Entity> create(const std::pair<float, float>& position);

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

        PlayerShip(std::shared_ptr<entities::Entity> associatedEntity);

        void update();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}


#endif //GRADIUS_PLAYERSHIP_H
