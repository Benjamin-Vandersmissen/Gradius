//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_TRANSFORMATION_H
#define GRADIUS_TRANSFORMATION_H


#include <utility>

class Transformation {
private:
    static unsigned int m_windowWidth;
    static unsigned int m_windowHeight;
    Transformation(unsigned int windowWidth, unsigned int windowHeight);
    static Transformation* m_transformation;
public:
    static void initTransformation(unsigned int windowWidth = 1920, unsigned int windowHeight = 1080);

    void resize(unsigned int windowWidth, unsigned int windowHeight);

    std::pair<double,double> transform(double pixelX, double pixelY);

    static Transformation* getTransformation();
};


#endif //GRADIUS_TRANSFORMATION_H
