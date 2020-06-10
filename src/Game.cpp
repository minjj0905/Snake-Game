#include "Game.h"
#include <math.h>
#include <string>
#include <unistd.h>
#include <iostream>
using namespace std;


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

    while(1) {
        timer.updateTime();
        double a = timer.getTick();
        if(a > 0.5) {
            curSnake.moveSnake();
            view.draw(curMap, curSnake);
            timer.startTimer();
        }
    }
    
}

// Test
int main() {
    Game game = Game();
    game.newGame();
    game.runGame();
    endwin();
}