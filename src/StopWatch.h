//
// Created by benji on 13.11.17.
//

#ifndef GRADIUS_STOPWATCH_H
#define GRADIUS_STOPWATCH_H
#include <chrono>
#include "Singleton.h"

class StopWatch : public Singleton<StopWatch>{
    friend class Singleton<StopWatch>;
private:
    std::chrono::steady_clock::time_point m_time;

    StopWatch();
public:
    /**
     * \brief set the clock to the current time
     * */
    void reset();

    /**
     * \brief get the difference between the current time and the time of initialization of the clock
     * */
    double getElapsedTime() const;
};


#endif //GRADIUS_STOPWATCH_H
