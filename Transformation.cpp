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

std::pair<double, double> Transformation::transform(double pixelX, double pixelY) {
    double x =  -4 + 8*(pixelX/m_windowWidth);
    double y =  -3 + 6*(pixelY/m_windowHeight);
    return std::pair<double, double>(x,y);
}

Transformation *Transformation::getTransformation() {
    return m_transformation;
}

