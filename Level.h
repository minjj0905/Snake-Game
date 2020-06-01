#include <iostream>

class Map {
public:
    int mapHeight = 0;
    int mapWidth = 0;
    int **map;
    std::string filename;
    std::string filepath;

    Map(int stage);

    void loadMap();
};

class Level {
public:
    int nowLevel;
    Map *maps;

    Level();
    Level(int stage);

    int getNowLevel();
};