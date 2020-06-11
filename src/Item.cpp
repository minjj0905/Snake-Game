#include <iostream>
#include "Item.h"
using namespace std;

POSITION::POSITION(int row, int col) {
    x = col;
    y = row;
}

Item::Item(Map& m, int type, int y, int x) {
    srand((unsigned int) time(0));
    if (m.map[rand() % m.mapHeight][rand() % m.mapWidth] == 0) {
        if (rand() % 2 == 0) {
            pos = POSITION(y, x);
            itemType = 0;
        } else {
            pos = POSITION(y, x);
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

