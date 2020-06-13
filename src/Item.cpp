#include <iostream>
#include "Item.h"
using namespace std;

Item::Item(Map m, Snake s) {
    do {
        setItemPos(m);
    } while (missSnakePos(s));
}

void Item::setItemPos(Map m) {
    srand((unsigned int)time(0));
    int x = (rand() % (m.mapWidth - 1)) + 1;
    int y = (rand() % (m.mapHeight - 1)) + 1;
    if (m.map[y][x] == 0) {
        if (rand() % 2 == 0) {
            pos = POSITION(y, x);
            itemType = 0;
        } else {
            pos = POSITION(y, x);
            itemType = 1;
        }
    }
}

bool Item::missSnakePos(Snake s) {
    for (int i = 0; i < s.getLength(); i++) {
        if ((s.snakePos[i].x == pos.x) || (s.snakePos[i].y == pos.y)) {
            return true;
        }
    }
    return false;
}

POSITION Item::getItemPos() {
    return pos;
}

bool Item::isGrowItem() {
    if(itemType) return false;
    return true;
}