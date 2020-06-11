#include "Game.h"
#include <math.h>
#include <string>


void Game::newGame() {
    view = View();
    level = Level();
    level.createMap();

    keypad(stdscr, TRUE);

    view.drawStartScreen();
    getch();

    nodelay(stdscr, TRUE);
    cbreak();
}

void Game::runGame() {
    runLevel();
    timer.resetTimer();
}

void Game::runLevel() {
    timer.startTimer();
    int tick = 0;
    int count = 0;

    curMap = level.getCurrentMap();
    curSnake = Snake(curMap);
    view.draw(curMap, curSnake);

    while(!isGameOver()) {
        timer.updateTime();
        double a = timer.getTick();
        if(a > 0.5) {
            curSnake.moveSnake();
            view.draw(curMap, curSnake);
            timer.startTimer();
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
    // mvprintw(20, 90, std::to_string(posvalue).c_str());
    // mvprintw(21, 90, std::to_string(headpos.y).c_str());
    // mvprintw(22, 90, std::to_string(headpos.x).c_str());
    if((posvalue == 1) || (posvalue == 2)) return true;

    return false;
}

// Test
int main() {
    Game game = Game();
    game.newGame();
    game.runGame();
    endwin();
}