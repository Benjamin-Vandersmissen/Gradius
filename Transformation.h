//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_TRANSFORMATION_H
#define GRADIUS_TRANSFORMATION_H


#include <utility>
#include "SFML/System/Vector2.hpp"
#include "Singleton.h"

class Transformation : public Singleton<Transformation>{
    friend class Singleton<Transformation>;
private:
    static unsigned int m_windowWidth;
    static unsigned int m_windowHeight;
    Transformation(){};
    Transformation(unsigned int windowWidth, unsigned int windowHeight);
    static Transformation* m_transformation;
    //y-coordinate of the top
    constexpr static float m_top = -3;
    //x-coordinate of the left
    constexpr static float m_left = -4;
    //width of the projection
    constexpr static float m_width = 8;
    //height of the projection
    constexpr static float m_height = 6;
public:
    /**
     * \brief set the width and height of the window and create the entity if not done already
     * */
    static void initTransformation(unsigned int windowWidth = 1920, unsigned int windowHeight = 1080);

    /**
     * \brief change the width and height of the window
     * */
    static void resize(unsigned int windowWidth, unsigned int windowHeight);

    /**
     * \brief transform window coordinates to game coordinates
     * */
    static std::pair<float,float> transform(unsigned int pixelX, unsigned int pixelY);

    /**
     * \brief transform game coordinates to window coordinates
     */

    static sf::Vector2f invTransform(const std::pair<float,float>& position);

    /**
     * \brief return x-value of the left
     * */
    static float left();

    /**
     * \brief return the y-value of the top
     * */
    static float top();

    /**
     * \brief return the width of the projection
     * */
    static float width();

    /**
     * \brief return the height of the projection
     * */
    static float height();

    /**
     * \brief return the width of the window
     * */
    static unsigned int windowWidth();

    /**
     * \brief return the height of the window
     * */
    static unsigned int windowHeight();
};


#endif //GRADIUS_TRANSFORMATION_H
