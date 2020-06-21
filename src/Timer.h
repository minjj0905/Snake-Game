#ifndef __TIMER__
#define __TIMER__

class Timer {
public:
    clock_t startTime;
    clock_t currentTime;
    double tick;

    Timer() {};
    
    ~Timer() {};

    /* Timer 시작 */
    void startTimer();

    /* 현재 시간을 업데이트 */
    void updateTime();

    /* 실행된 시간을 정수로 반환 - 화면 표시용 */
    unsigned int getPlayTime();

    /* 실행된 시간을 실수로 반환 - 계산용 */
    double getTick();

};
#endif