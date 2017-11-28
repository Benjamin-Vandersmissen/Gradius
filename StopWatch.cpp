//
// Created by benji on 13.11.17.
//

#include "StopWatch.h"

StopWatch::StopWatch() {
    m_time = std::chrono::steady_clock::now();

}

double StopWatch::getElapsedTime() const{
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now()- m_time).count();
}

void StopWatch::reset() {
    m_time = std::chrono::steady_clock::now();
}

