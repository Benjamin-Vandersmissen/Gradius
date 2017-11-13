//
// Created by benji on 13.11.17.
//

#include "StopWatch.h"

StopWatch::StopWatch() {
    m_clock = std::clock();
}

clock_t StopWatch::getElapsedTime() {
    return clock()-m_clock;
}
