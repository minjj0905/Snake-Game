#ifndef __SNAKE__
#define __SNAKE__

#include <iostream>
#include <vector>

class Snake {
public:
    
    /*길이*/
    int length = 3;

    /*머리 좌표*/
    std::vector<int> headPos;

    /*몸통 좌표*/
    std::vector<std::vector<int>> bodyPos;

    /*방향*/
    char direction;

    /*grow Item 먹은 횟수*/
    int growCount = 0;

    /*poison Item 먹은 횟수*/
    int poisonCount = 0;

    /*snake의 생사여부*/
    bool fail = false;


    /*snake의 생사 여부 반환*/
    bool isFailed();

    /*grow Item 을 먹은 횟수 반환*/
    int getGrowCount();

    /*poison Item 먹은 횟수 반환*/
    int getPoisonCount();

    /*snake의 길이 반환*/
    int getLength();

    /*snake가 죽음*/
    void setFailed();
};
#endif