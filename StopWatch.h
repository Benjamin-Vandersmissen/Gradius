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
    /**
     * \brief set the clock to the current time
     * */
    void reset();

    /**
     * \brief get the difference between the current time and the time of initialization of the clock
     * */
    clock_t getElapsedTime() const;

    /**
     * \brief creates the stopwatch if it wasn't created yet and returns it
     * */
    static StopWatch * getStopWatch();
};


#endif //GRADIUS_STOPWATCH_H
