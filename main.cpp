#include <iostream>
#include "StopWatch.h"
int main() {
    StopWatch* stopWatch = StopWatch::getStopWatch();
    std::cout <<  "-------" << std::endl << stopWatch->getElapsedTime() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}