//
// Created by benji on 10.02.18.
//

#include <iostream>
#include "Hitbox.h"

size_t Hitbox::addPoint(const sf::Vector2f &point) {
    m_hitbox.setPointCount(m_hitbox.getPointCount()+1);
    m_hitbox.setPoint(m_nrPoints, point);
    m_graphicRepresentation.setPointCount(m_graphicRepresentation.getPointCount()+1);
    m_graphicRepresentation.setPoint(m_nrPoints,Transformation::invTransform(std::pair<float,float>(point.x, point.y)));
    return m_nrPoints++;
}

const sf::ConvexShape &Hitbox::get() const {
    return m_hitbox;
}

bool Hitbox::intersects(const Hitbox &hitbox) {
    if(!hitbox.bounds().intersects(bounds())) //rudimental check based on bounding boxes, not very sophisticated
        return false;
    for(size_t i = 0; i < m_nrPoints; ++i){
        //make representation of line i in the form of : y = a*x + b
        sf::Vector2f point1 = hitbox.get().getPoint(i);
        sf::Vector2f point2 = hitbox.get().getPoint((i+1)%m_nrPoints);
        float a1 = (point2.y-point1.y)/(point2.x-point1.x);
        float b1 = point1.y - a1*point1.x;
        for(size_t i = 0; i < m_nrPoints; ++i) {
            //make representation of line i in the form of : y = a*x + b
            sf::Vector2f point3 = get().getPoint(i);
            sf::Vector2f point4 = get().getPoint((i + 1) % m_nrPoints);
            float a2 = (point4.y - point3.y) / (point4.x - point3.x);
            float b2 = point3.y - a2 * point3.x;

            if(a1 == a2 && b1 == b2) //the lines are the same
                return true;
            if(a1 == a2) //the lines are parallel -> no intersection
                continue;
            float x = (b1-b2)/(a2-a1);
            float y = a2*x+b2;
            if(((point1.x <= x && point2.x >= x) || (point2.x <= x && point1.x >= x)) &&((point3.x <= x && point4.x >= x) || (point4.x <= x && point3.x >= x)))
                return true;
        }
    }
    return false;
}

const sf::ConvexShape &Hitbox::getGraphicRepresentation() const {
    return m_graphicRepresentation;
}

Hitbox operator+(const Hitbox &lhs, const sf::Vector2f &rhs) {
    Hitbox retval = Hitbox();
    for(size_t i = 0; i < lhs.get().getPointCount(); ++i){
        retval.addPoint(lhs.m_hitbox.getPoint(i) + rhs);
    }
    return retval;
}

void Hitbox::print() {
    for(size_t i = 0; i < m_nrPoints; ++i){
        std::cout << m_graphicRepresentation.getPoint(i).x << ' ' << m_graphicRepresentation.getPoint(i).y << std::endl;
    }
}

sf::FloatRect Hitbox::bounds() const {
    return m_hitbox.getLocalBounds();
};
