//
// Created by benji on 13.11.17.
//

#include "StopWatch.h"

StopWatch* StopWatch::m_stopwatch = nullptr;

StopWatch::StopWatch() {
    m_clock = std::clock();
}

clock_t StopWatch::getElapsedTime() const{
    return clock()-m_clock;
}

void StopWatch::reset() {
    m_clock = clock();
}

StopWatch * StopWatch::getStopWatch(){
    if(!StopWatch::m_stopwatch)
        StopWatch::m_stopwatch = new StopWatch;
    return StopWatch::m_stopwatch;
}
