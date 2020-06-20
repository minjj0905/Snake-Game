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

    /*Gate의 pos지정*/
    void setGatePos(Map m);

    /*Gate의 pos 반환 */
    POSITION getGatePos(int n);

    /*반대 Gate Pos*/
    POSITION getOtherPos(POSITION p);
};
#endif