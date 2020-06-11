#ifndef __ITEM__
#define __ITEM__

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Map.h"
#include "Snake.h"

struct POSITION {
    int x, y;
    POSITION(int y, int x);
    POSITION() {};
};

class Item {
public :

    Item() {};

    Item(Map m, Snake s);

    POSITION pos;

    /*아이템의 타입 grow = 0, poison = 1*/
    int itemType;

    /*각 아이템들의 좌표값을 리턴*/
    POSITION getItemPos();

    /*type이 grow인지 판별*/
    bool isGrowItem();

};
#endif