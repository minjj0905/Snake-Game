#include <iostream>
#include "Item.h"
using namespace std;

POSITION::POSITION(int row, int col) {
    x = col;
    y = row;
}

POSITION::POSITION() {
    x = 0;
    y = 0;
}

Item::Item() {
    int itemCount = 0;
    string itemType = "";
}

void Item::randomItem(Map& m) {
    srand((unsigned int) time(0));
    if ((m.map[rand() % m.mapHeight][rand() % m.mapWidth] == 0) && (itemCount < 3)) {
        if (rand() % 2 == 0) {
            growItem(rand() % m.mapHeight, rand() % m.mapWidth);
            itemCount++;
        } else {
            poisonItem(rand() % m.mapHeight, rand() % m.mapWidth);
            itemCount++;
        }
    }
}

void Item::growItem(int y, int x) {
    growItemPos.push_back(POSITION(y, x));
    itemType = "grow";
}

void Item::poisonItem(int y, int x) {
    poisonItemPos.push_back(POSITION(y, x));
    itemType = "poison";
}

POSITION Item::getItemPos() {
    if (itemType == "grow" && !growItemPos.empty()) {
        int xpos = growItemPos[0].x;
        int ypos = growItemPos[0].y;
        growItemPos.clear();
        return POSITION(ypos, xpos);
    } else if (itemType == "poison" && !poisonItemPos.empty()) {
        int xpos = poisonItemPos[0].x;
        int ypos = poisonItemPos[0].y;
        poisonItemPos.clear();
        return POSITION(ypos, xpos);
    } else {
        return POSITION();
    }
}


