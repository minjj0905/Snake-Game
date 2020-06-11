#include <ncurses.h>
#include "Snake.h"

POSITION::POSITION(int row, int col) {
    x = col;
    y = row;
}

POSITION::POSITION() {
    x = 0;
    y = 0;
}

Snake::Snake(Map& m) {
    for (int i = 0; i < m.mapHeight; i++) {
        for (int j = 0; j < m.mapWidth; j++) {
            if (m.map[i][j] == 3) {
                snakePos.push_back(POSITION(i, j));
                m.map[i][j] = 0;
            } else if (m.map[i][j] == 4) {
                snakePos.push_back(POSITION(i, j));
                m.map[i][j] = 0;
            }
        }
    }
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

void Snake::moveSnake() {
    int KeyPressed = getch();
    switch(KeyPressed) {
        case KEY_LEFT:
            if (direction != 'r') {
                direction = 'l';
                break;
            } else {
                setFailed();
                break;
            }
        case KEY_RIGHT:
            if (direction != 'l') {
                direction = 'r';
                break;
            } else {
                setFailed();
                break;
            }
        case KEY_UP:
            if (direction != 'd') {
                direction = 'u';
                break;
            } else {
                setFailed();
                break;
            }
        case KEY_DOWN:
            if (direction != 'u') {
                direction = 'd';
                break;
            } else {
                setFailed();
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

    checkCorrectPos();
}

void Snake::checkCorrectPos() {
    POSITION headpos = snakePos[0];
    for(int i=1; i<getLength(); i++) {
        POSITION bodypos = snakePos[i];
        if(bodypos.x == headpos.x && bodypos.y == headpos.y) {
            setFailed();
        }
    }
}


std::vector<POSITION> Snake::getPosition() {
    return snakePos;
}