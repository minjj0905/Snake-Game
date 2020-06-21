#ifndef __GATE__
#define __GATE__

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Map.h"
#include "Snake.h"

class Gate{
public:
    Gate() {};

    Gate(Map m);

    /*Gate의 좌표들*/
    POSITION pos1;
    POSITION pos2;

    /* 상하좌우 value */
    int pos1_udlr[4];
    int pos2_udlr[4];

    /*Gate의 pos지정*/
    void setGatePos(Map m);

    /* 상하좌우값 저장 */
    void setUdlr(Map m);

    /* 상하좌우값 반환 */
    int getUdlr(int posnum, int idx);

    /*Gate의 pos 반환 */
    POSITION getGatePos(int n);

    /*반대 Gate Pos*/
    POSITION getOtherPos(POSITION p);

    /*Gate의 입구 공유 여부*/
    bool preventShare(int x1, int y1, int x2, int y2);
};
#endif