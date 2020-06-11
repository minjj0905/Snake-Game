#include <iostream>
#include "Item.h"
using namespace std;

POSITION::POSITION(int row, int col) {
    x = col;
    y = row;
}

Item::Item(Map m, Snake s) {
    srand((unsigned int) time(0));
    int errcnt = 0;
    for (int i = 0; i < s.snakePos.size(); i++) {
        if ((s.snakePos[i].y == rand() % m.mapHeight + 1) || (s.snakePos[i].x == rand() % m.mapWidth + 1)) {
            errcnt++;
        }
    }
    if ((m.map[rand() % m.mapHeight + 1][rand() % m.mapWidth + 1] == 0) && errcnt == 0) {
        if (rand() % 2 == 0) {
            pos = POSITION(rand() % m.mapHeight + 1, rand() % m.mapWidth + 1);
            itemType = 0;
        } else {
            pos = POSITION(rand() % m.mapHeight + 1, rand() % m.mapWidth + 1);
            itemType = 1;
        }
    }
}

POSITION Item::getItemPos() {
    return pos;
}

bool Item::isGrowItem() {
    if(itemType) return false;
    return true;
}

