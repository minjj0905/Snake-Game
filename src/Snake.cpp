#include <iostream>
#include <vector>
// #include <ncurses.h>
#include "Snake.h"
using namespace std;

POSITION::POSITION(int row, int col) {
    x = col;
    y = row;
}

POSITION::POSITION() {
    x = 0;
    y = 0;
}

Snake::Snake() {}

Snake::Snake(Level& lv) {

}

bool Snake::isFailed() {
    return fail;
}

int Snake::getGrowCount() {
    return growCount;
}

int Snake::getPoisonCount() {
    return poisonCount;
}

int Snake::getLength() {
    return snakePos.size();
}

void Snake::setFailed() {
    fail = true;
}

void Snake::initSnake(Level& lv) {
    for (int i = 0; i < lv.maps[lv.currentLevel].mapHeight; i++) {
        for (int j = 0; j < lv.maps[lv.currentLevel].mapWidth; j++) {
            if (lv.maps[lv.currentLevel].map[i][j] == 3) {
                snakePos.push_back(POSITION(i, j));
            } else if (lv.maps[lv.currentLevel].map[i][j] == 4) {
                snakePos.push_back(POSITION(i, j));
            }
        }
    }
}

void Snake::moveSnake() {
    int KeyPressed = getch();
    switch(KeyPressed) {
        case KEY_LEFT:
            if (direction != 'r') {
                direction = 'l';
                break;
            }
        case KEY_RIGHT:
            if (direction != 'l') {
                direction = 'r';
                break;
            }
        case KEY_UP:
            if (direction != 'd') {
                direction = 'u';
                break;
            }
        case KEY_DOWN:
            if (direction != 'u') {
                direction = 'd';
                break;
            }
    }

    if (direction == 'l') {
        snakePos.insert(snakePos.begin(), POSITION(snakePos[0].y, snakePos[0].x - 1));
        snakePos.pop_back();
    } else if (direction == 'r') {
        snakePos.insert(snakePos.begin(), POSITION(snakePos[0].y, snakePos[0].x + 1));
        snakePos.pop_back();
    } else if (direction == 'u') {
        snakePos.insert(snakePos.begin(), POSITION(snakePos[0].y - 1, snakePos[0].x));
        snakePos.pop_back();
    } else if (direction == 'd') {
        snakePos.insert(snakePos.begin(), POSITION(snakePos[0].y + 1, snakePos[0].x));
        snakePos.pop_back();
    }
}

int main() {
    Level l = Level();
    l.createMap();
    Snake s = Snake();
    s.initSnake(l);
    cout << "snakePos vector" << endl;
    for (int i = 0; i < s.snakePos.size(); i++) {
        cout << s.snakePos[i].y << " " << s.snakePos[i].x << endl;
    }
}