#include "Game.h"
#include <math.h>
#include <string>
#include <iostream>
using namespace std;


void Game::newGame() {
    view = View();
    level = Level();
    level.createMap();

    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    view.drawStartScreen();
    getch();
    clear();
}

void Game::runGame() {
    runLevel();
    timer.resetTimer();
}

void Game::runLevel() {
    double tick = 0;
    int key;
    curMap = level.getCurrentMap();
    view.draw(curMap, curSnake);    

    timer.startTimer();
    while(1) {
        timer.updateTime();
        tick = timer.getTick();
        key = getch();
        if(key == KEY_DOWN) break;
        if(fmod(tick, 0.5) == 0) {
            mvprintw(4, 80, to_string(tick).c_str());
        }
        refresh();
    }
}

// Test
int main() {
    Game game = Game();
    game.newGame();
    game.runGame();
    endwin();
}