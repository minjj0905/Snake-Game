#include <iostream>
#include "Level.h"
using namespace std;

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