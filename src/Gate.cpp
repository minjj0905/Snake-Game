#include <iostream>
#include "Gate.h"
using namespace std;

Gate::Gate(Map m) {
    setGatePos(m);
}

void Gate::setGatePos(Map m) {
    srand((unsigned int)time(0));
    int x1 = rand() % m.mapWidth;
    int y1 = rand() % m.mapHeight;
    int x2 = rand() % m.mapWidth;
    int y2 = rand() % m.mapHeight;
    if (m.map[y1][x1] == 1) {
        pos1 = POSITION(y1, x1);
    } else {
        while (m.map[y1][x1] != 1) {
            x1 = rand() % m.mapWidth;
            y1 = rand() % m.mapHeight;
            pos1 = POSITION(y1, x1);
        }
    }
    if (m.map[y2][x2] == 1 && (x1 != x2 || y1 != y2)) {
        pos2 = POSITION(y2, x2);
    } else {
        while (m.map[y2][x2] != 1 || (x1 == x2 && y1 == y2)) {
            x2 = rand() % m.mapWidth;
            y2 = rand() % m.mapHeight;
            pos2 = POSITION(y2, x2);
        }
    }
    setUdlr(m);
}

void Gate::setUdlr(Map m) {
    int h = m.mapHeight;
    int w = m.mapWidth;

    int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    
    //pos1
    for(int i=0; i<4; i++) {
        if((pos1.y+dir[i][0] <= h) && (pos1.y+dir[i][0] >= 0) && (pos1.x+dir[i][1] <= w) && (pos1.x+dir[i][1] >= 0)) {
            pos1_udlr[i] = m.getMapValue(pos1.y+dir[i][0], pos1.x+dir[i][1]);
        }
        else {
            pos1_udlr[i] = 2;
        }
    }

    //pos2
    for(int i=0; i<4; i++) {
        if((pos2.y+dir[i][0] <= h) && (pos2.y+dir[i][0] >= 0) && (pos2.x+dir[i][1] <= w) && (pos2.x+dir[i][1] >= 0)) {
            pos2_udlr[i] = m.getMapValue(pos2.y+dir[i][0], pos2.x+dir[i][1]);
        }
        else {
            pos2_udlr[i] = 2;
        }
    }
}

POSITION Gate::getGatePos(int n) {
    if (n == 1) {
        return pos1;
    }else if (n ==2) {
        return pos2;
    }
}

POSITION Gate::getOtherPos(POSITION p) {
    if (p == pos1) return pos2;
    else if (p == pos2) return pos1;
}