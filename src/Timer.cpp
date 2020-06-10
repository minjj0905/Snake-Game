#include <time.h>
#include <math.h>
#include "Timer.h"

#include <iostream>
using namespace std;

void Timer::startTimer(){
    startTime = clock();
}

void Timer::resetTimer(){
    startTime = 0;
    currentTime = 0;
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

/* timer 테스트용 코드 */
// int main() {
//     Timer timer;
//     timer.startTimer();
//     double a = 0;
//     int playtime = 0;
//     while(a < 5) {
//         timer.updateTime();
//         a = timer.getTick();
//         playtime = timer.getPlayTime();
//         if(fmod(a, 0.5) == 0) {
//             cout << "tick = "  << a << ", playtime = " << playtime << endl;
//         }
//     }
// }