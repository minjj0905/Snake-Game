#ifndef __ITEM__
#define __ITEM__

#include <iostream>
#include <cstdlib>
#include "Map.h"

class Item {
public :
    
    /*맵에 나와있는 아이템의 전체 갯수*/
    int itemCount = 0;

    char poison;

    char grow;

    void poisonItem();

    void growItem();

    void randomItem(Map& m);



};
#endif