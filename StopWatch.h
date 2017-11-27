//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_STOPWATCH_H
#define GRADIUS_STOPWATCH_H
#include <chrono>

class StopWatch {
private:
    std::chrono::steady_clock::time_point m_time;

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
    double getElapsedTime() const;

    /**
     * \brief creates the stopwatch if it wasn't created yet and returns it
     * */
    static StopWatch * getStopWatch();
};


#endif //GRADIUS_STOPWATCH_H
