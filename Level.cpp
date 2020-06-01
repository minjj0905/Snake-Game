#include <iostream>
#include <fstream>
#include "Level.h"
using namespace std;

#define LevelDir "./levels/"
#define file "level"

//Level
/*Level 기본 생성자, 생성시 nowLevel을 0으로 초기화*/
Level::Level() {
    nowLevel = 0;
}

/*nowLevel을 stage 값으로 초기화하며 Level 객체 생성*/
Level::Level(int stage) {
    nowLevel = stage;
}

/*nowlevel return*/
int Level::getNowLevel() {
    return nowLevel;
}

//Map
/*Map 객체 생성, stage로 filepath 지정*/
Map::Map(int stage) {
    filename = file + to_string(stage);
    filepath = LevelDir + filename + ".txt";
}

/*level txt 로드하여 map배열, width, height 저장*/
void Map::loadMap() {
    ifstream in(filepath);
    in >> mapHeight >> mapWidth;
    map = new int *[mapHeight];
    for(int i=0; i<mapHeight; i++) {
        map[i] = new int [mapWidth];
        for(int j=0; j<mapWidth; j++) {
            in >> map[i][j];
        }
    }
}

//Level, map test
int main() {
    Level level;
    // cout << level.getNowLevel() << endl;

    Map map(level.getNowLevel());
    map.loadMap();

    cout << map.mapHeight << endl;
    cout << map.map[0][0] << endl;    
}