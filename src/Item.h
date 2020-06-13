#ifndef __ITEM__
#define __ITEM__

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Map.h"
#include "Snake.h"

class Item {
public :

    Item() {};

    Item(Map m, Snake s);

    /*아이템의 좌표*/
    POSITION pos;

    /*아이템의 좌표값 설정*/
    void setItemPos(Map m);

    /*아이템의 좌표랑 스네이크의 좌표랑 같은지 확인*/
    bool missSnakePos(Snake s);

    /*아이템의 타입 grow = 0, poison = 1*/
    int itemType;

    /*각 아이템들의 좌표값을 리턴*/
    POSITION getItemPos();

    /*type이 grow인지 판별*/
    bool isGrowItem();

    bool operator==(Item& i);

};
#endif