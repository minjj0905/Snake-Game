#include "Level.h"

Level::Level() {
    currentLevel = 0;
}

int Level::getCurrentLevel() {
    return currentLevel;
}

void Level::upCurrentLevel() {
    currentLevel++;
}

Map Level::getCurrentMap() {
    return maps[currentLevel];
}

void Level::createMap() {
    for (int i = 0; i < 4; i++) {
        maps[i] = Map(i);
        missions[i] = Mission(i);
        clear[i] = false;
    }
}

void Level::setClear(bool b) {
    clear[currentLevel] = b;
}

bool Level::getClear() {
    return clear[currentLevel];
}

Mission Level::getMission() {
    return missions[currentLevel];
}