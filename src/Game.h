#ifndef __GAME__
#define __GAME__

#include "View.h"
#include "Timer.h"
#include "Gate.h"
#include "Item.h"

class Game {
public:
    View view;
    Level level;
    Snake curSnake;
    Map curMap;
    int curLv;
    std::vector <Gate> gate;
    std::vector<Item> item;

    Game() {};
    void newGame();
    void runGame();
    void runLevel();
    void clearGame();
    void event();
    bool isGameOver();
    bool isCollision();
    bool isGetItem();
    bool isOnGate();
    void isGameClear();

};

#endif