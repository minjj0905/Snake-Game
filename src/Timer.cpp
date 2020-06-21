#include <time.h>
#include <math.h>
#include "Timer.h"

#include <iostream>
using namespace std;

void Timer::startTimer(){
    startTime = clock();
}

void Timer::updateTime() {
    currentTime = clock();
    tick = (double)(currentTime - startTime)/CLOCKS_PER_SEC;
}

unsigned int Timer::getPlayTime() {
    return tick;
}

double Timer::getTick() {
    return tick;
}