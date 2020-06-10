#ifndef __ITEM__
#define __ITEM__

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Map.h"

struct POSITION {
    int x, y;
    POSITION(int y, int x);
    POSITION();
};

class Item {
public :

    Item();
    
    /*맵에 나와있는 아이템의 전체 갯수*/
    int itemCount = 0;

    /*아이템의 타입 grow, poison*/
    string itemType = "";

    /*grow 아이템의 정보를 갖게한다.*/
    void growItem(int y, int x);

    /*poison 아이템의 정보를 갖게한다.*/
    void poisonItem(int y, int x);

    /*랜덤으로 아이템 생성*/
    void randomItem(Map& m);

    /*각 아이템들의 좌표*/
    vector<POSITION> growItemPos;
    vector<POSITION> poisonItemPos;

    /*각 아이템들의 좌표값을 리턴*/
    POSITION getItemPos();

};
#endif