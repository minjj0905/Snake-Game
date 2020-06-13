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
}