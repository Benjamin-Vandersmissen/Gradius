//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_STOPWATCH_H
#define GRADIUS_STOPWATCH_H
#include <ctime>

class StopWatch {
private:
    clock_t m_clock;

    StopWatch();

    static StopWatch* m_stopwatch;
public:
    void reset();

    clock_t getElapsedTime() const;

    static StopWatch * getStopWatch();
};


#endif //GRADIUS_STOPWATCH_H
