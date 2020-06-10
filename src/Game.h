#ifndef __GAME__
#define __GAME__

#include "View.h"
#include "Timer.h"
// #include "Gate.h"
// #include "Item.h"

class Game {
public:
    View view;
    Timer timer;
    Level level;
    Snake curSnake;
    Map curMap;
    int curLv;

    Game() {};
    void newGame();
    void runGame();
    void runLevel();
    void clearGame();
    void event();
    void isGameOver();
    void isGameClear();

};

#endif