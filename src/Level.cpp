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
    }
}