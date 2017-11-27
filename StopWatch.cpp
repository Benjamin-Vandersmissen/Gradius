//
// Created by benji on 13.11.17.
//

#include "StopWatch.h"

StopWatch* StopWatch::m_stopwatch = nullptr;

StopWatch::StopWatch() {
    m_time = std::chrono::steady_clock::now();

}

double StopWatch::getElapsedTime() const{
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now()- m_time).count();
}

void StopWatch::reset() {
    m_time = std::chrono::steady_clock::now();
}

StopWatch * StopWatch::getStopWatch(){
    if(!StopWatch::m_stopwatch)
        StopWatch::m_stopwatch = new StopWatch;
    return StopWatch::m_stopwatch;
}
