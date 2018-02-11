//
// Created by benji on 10.02.18.
//

#ifndef GRADIUS_HITBOX_H
#define GRADIUS_HITBOX_H


#include <SFML/Graphics/ConvexShape.hpp>
#include "Transformation.h"

class Hitbox {
private:
    sf::ConvexShape m_hitbox = sf::ConvexShape(0);
    sf::ConvexShape m_graphicRepresentation = sf::ConvexShape(0);
    size_t m_nrPoints = 0;
public:
    /**
     * @brief add a vector to each point of the hitbox, thus moving the hitbox across the vector
     * */
    friend Hitbox operator+(const Hitbox& lhs, const sf::Vector2f& rhs);

    /**
     * @brief add a new point to the hitbox
     *
     * @return the index of the point
     * */
    size_t addPoint(const sf::Vector2f &point);

    /**
     * @brief get the sf::ConvexShape of the hitbox
     * */
    const sf::ConvexShape &get() const;

    /**
     * @brief returns the hitbox in window coordinates, for debug purposes only
     * */
    const sf::ConvexShape &getGraphicRepresentation() const;

    /**
     * @brief check whether two hitboxes intersect or not
     * */
    bool intersects(const Hitbox &hitbox);

    /**
     * @brief get the bounding box of the hitbox, the minimal rectangle that contains all the points
     * */
    sf::FloatRect bounds() const;

    /**
     * @brief prints each point of the hitbox, for debug purposes only
     * */
    void print();
};


#endif //GRADIUS_HITBOX_H
