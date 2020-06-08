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

void Level::createMap() {
    for (int i = 0; i < 4; i++) {
        cout << i << endl;
        maps[i] = Map(i);
    }
}

/*test*/
int main() {
    Level l = Level();
    cout << "1" << endl;
    l.createMap();
    cout << "10" << endl;
    cout << l.maps[0].getMapValue(10, 10) << endl;
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            cout << l.maps[0].map[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            cout << l.maps[1].map[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            cout << l.maps[2].map[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            cout << l.maps[3].map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}