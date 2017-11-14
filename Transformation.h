//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_TRANSFORMATION_H
#define GRADIUS_TRANSFORMATION_H


#include <utility>
#include "SFML/System/Vector2.hpp"

class Transformation {
private:
    static unsigned int m_windowWidth;
    static unsigned int m_windowHeight;
    Transformation(unsigned int windowWidth, unsigned int windowHeight);
    static Transformation* m_transformation;
public:
    static void initTransformation(unsigned int windowWidth = 1920, unsigned int windowHeight = 1080);

    static void resize(unsigned int windowWidth, unsigned int windowHeight);

    /**
     * Window Coordinates => Game Coordinates
     * */
    static std::pair<float,float> transform(unsigned int pixelX, unsigned int pixelY);

    static Transformation* getTransformation();

    /**
     * Game Coordinates => Window Coordinates
     */

    static sf::Vector2f invTransform(const std::pair<float,float>& position);
};


#endif //GRADIUS_TRANSFORMATION_H
