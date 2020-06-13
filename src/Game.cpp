#include "Game.h"
#include <math.h>
#include <string>


void Game::newGame() {
    view = View();
    level = Level();
    level.createMap();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    cbreak();
    view.drawStartScreen();
    getch();
}

void Game::runGame() {
    runLevel();
}

void Game::runLevel() {
    srand((unsigned int)time(0));

    Timer levelTimer;
    Timer itemTimer;
    Timer gateTimer;
    Timer tickTimer;
    Timer eraseTimer;

    curMap = level.getCurrentMap();
    curSnake = Snake(curMap);
    view.draw(curMap, curSnake, item);

    levelTimer.startTimer();
    itemTimer.startTimer();
    gateTimer.startTimer();
    tickTimer.startTimer();

    double tick;
    double itemtime;
    double erasetime;
    double gatetime;
    int playtime;

    while(!isGameOver()) {
        view.update();

        levelTimer.updateTime();
        itemTimer.updateTime();
        eraseTimer.updateTime();
        gateTimer.updateTime();
        tickTimer.updateTime();

        playtime = levelTimer.getPlayTime();
        tick = tickTimer.getTick();
        itemtime = itemTimer.getTick();
        erasetime = eraseTimer.getTick();

        curSnake.setDirection();

        if(tick > 0.5) {
            curSnake.moveSnake();

            if(!isGetItem()) {
                if((erasetime > rand() % 3 + 7) && !item.empty()) {
                    item.erase(item.begin());
                    eraseTimer.startTimer();
                }
            }
            view.draw(curMap, curSnake, item);
            tickTimer.startTimer();
        }

        if(itemtime > rand() % 3 + 3) {
            if(item.size() < 3) {
                Item newitem = Item(curMap, curSnake);
                item.push_back(newitem);
            }
            itemTimer.startTimer();
        }
    }
    view.drawGameOver();
}

bool Game::isGameOver() {
    //Snake 키보드 입력 체크
    if(curSnake.isFailed()) return true;
    if(isCollision()) return true;

    return false;
}

bool Game::isCollision() {
    POSITION headpos = curSnake.getPosition()[0];
    int posvalue = curMap.getMapValue(headpos.y, headpos.x);
    if((posvalue == 1) || (posvalue == 2)) return true;

    return false;
}

bool Game::isGetItem() {
    POSITION headpos = curSnake.getPosition()[0];
    for(int i=0; i<item.size(); i++) {
        POSITION itempos = item[i].getItemPos();
        if(headpos.x == itempos.x && headpos.y == itempos.y) {
            if(item[i].isGrowItem()) {
                curSnake.eatGrowItem();
            }else {
                curSnake.eatPoisonItem();
            }
            item.erase(item.begin()+i);
            return true;
        }
    }
    return false;
}

// Test
int main() {
    Game game = Game();
    game.newGame();
    game.runGame();
    endwin();
}