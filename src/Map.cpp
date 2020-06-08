#include <iostream>
#include <fstream>
#include "Map.h"
using namespace std;

#define LevelDir "../levels/"
#define file "level"

Map::Map() {}

Map::Map(int stage) {
    cout << "Map create" << endl;
    mapPath = (string)LevelDir + file + to_string(stage) + ".txt";
    loadMap();
}

void Map::loadMap() {
    cout << "loadMap" << endl;
    cout << mapPath << endl;
    ifstream in(mapPath);
    in >> mapHeight >> mapWidth;
    map = new int *[mapHeight];
    for (int i = 0; i < mapHeight; i++) {
        map[i] = new int [mapWidth];
        for (int j = 0; j < mapWidth; j++) {
            in >> map[i][j];
        }
    }
}

int Map::getMapValue(int y, int x) {
    return map[y][x];
}

void Map::setMapValue(int y, int x, int value) {
    map[y][x] = value;
}

vector<int> Map::getMapPos(int value) {
    vector<int> v;
    for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWidth; j++) {
            if (map[i][j] == value) {
                v.push_back(i);
                v.push_back(j);
            }
        }
    }
    return v;
}