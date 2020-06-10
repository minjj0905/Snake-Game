#ifndef __SNAKE__
#define __SNAKE__

#include <vector>
#include "Map.h"

struct POSITION {
    int x, y;
    POSITION(int y, int x);
    POSITION();
};

class Snake {
public:

    Snake() {};
    Snake(Map& m);

    /*스네이크의 좌표*/
    std::vector<POSITION> snakePos;

    /*방향*/
    char direction = 'l';

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

    /*키를 받고 snake 방향전환함*/
    void moveSnake();

    /* Snake Position */
    std::vector<POSITION> getPosition();
};
#endif

/*움직이는 것처럼 보이게 하는게 머리 한칸 옮기고 반영, 꼬리한칸 없애고 반영 move()를 사용할 수 있는가*/