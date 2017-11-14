//
// Created by benji on 13.11.17.
//

#include "Transformation.h"

unsigned int Transformation::m_windowWidth = 0;
unsigned int Transformation::m_windowHeight = 0;
Transformation* Transformation::m_transformation = nullptr;

Transformation::Transformation(unsigned int windowWidth, unsigned int windowHeight) {
     m_windowHeight = windowHeight;
     m_windowWidth = windowWidth;
}

void Transformation::initTransformation(unsigned int windowWidth, unsigned int windowHeight) {
    if(!m_transformation){
        m_transformation = new Transformation(windowWidth, windowHeight);
    }
    m_transformation->resize(windowWidth, windowHeight);
}

void Transformation::resize(unsigned int windowWidth, unsigned int windowHeight) {
    m_windowWidth = windowWidth;
    m_windowHeight = windowHeight;
}

std::pair<float, float> Transformation::transform(unsigned int pixelX, unsigned int pixelY) {
    float x =  -4 + 8* (static_cast<float>(pixelX)/m_windowWidth);
    float y =  -3 + 6*(static_cast<float>(pixelY)/m_windowHeight);
    return std::pair<float, float>(x,y);
}

Transformation *Transformation::getTransformation() {
    return m_transformation;
}

sf::Vector2f Transformation::invTransform(std::pair<float, float> &position) {
    float x = (position.first+4)/8*m_windowWidth;
    float y = (position.second+3)/6*m_windowHeight;
    return sf::Vector2f(x,y);
}

