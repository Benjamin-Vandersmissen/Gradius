//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_STOPWATCH_H
#define GRADIUS_STOPWATCH_H
#include <ctime>

class StopWatch {
    clock_t m_clock;
public:
    StopWatch();

    clock_t getElapsedTime();
};


#endif //GRADIUS_STOPWATCH_H
