#include <ncursesw/ncurses.h>
#include "Snake.h"

POSITION::POSITION(int row, int col) {
    x = col;
    y = row;
}

POSITION::POSITION() {
    x = 0;
    y = 0;
}

bool POSITION::operator==(POSITION& p) {
    return ((x == p.x) && (y == p.y));
}

Snake::Snake(Map& m) {
    direction = 'l';
    maxLength = 3;
    curLength = 3;
    growCount = 0;
    poisonCount = 0;
    fail = false;
    tailPos.push_back(POSITION());
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

void Snake::setDirection() {
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
}

void Snake::moveSnake() {
    if (direction == 'l') {
        snakePos.insert(snakePos.begin(), POSITION(snakePos[0].y, snakePos[0].x - 1));
        tailPos.pop_back();
        tailPos.push_back(POSITION(snakePos[snakePos.size()-1].y, snakePos[snakePos.size()-1].x));
        snakePos.pop_back();
    } else if (direction == 'r') {
        snakePos.insert(snakePos.begin(), POSITION(snakePos[0].y, snakePos[0].x + 1));
        tailPos.pop_back();
        tailPos.push_back(POSITION(snakePos[snakePos.size()-1].y, snakePos[snakePos.size()-1].x));
        snakePos.pop_back();
    } else if (direction == 'u') {
        snakePos.insert(snakePos.begin(), POSITION(snakePos[0].y - 1, snakePos[0].x));
        tailPos.pop_back();
        tailPos.push_back(POSITION(snakePos[snakePos.size()-1].y, snakePos[snakePos.size()-1].x));
        snakePos.pop_back();
    } else if (direction == 'd') {
        snakePos.insert(snakePos.begin(), POSITION(snakePos[0].y + 1, snakePos[0].x));
        tailPos.pop_back();
        tailPos.push_back(POSITION(snakePos[snakePos.size()-1].y, snakePos[snakePos.size()-1].x));
        snakePos.pop_back();
    }

    // 스네이크 fail 체크
    checkCorrectPos();
    checkLength();
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

void Snake::checkLength() {
    if (getLength()<3) setFailed();
}

std::vector<POSITION> Snake::getPosition() {
    return snakePos;
}

void Snake::setMaxLength() {
    if (getLength() > maxLength) {
        maxLength = getLength();
    }
}

void Snake::eatGrowItem() {
    int x = tailPos[tailPos.size()-1].x;
    int y = tailPos[tailPos.size()-1].y;
    snakePos.push_back(POSITION(y, x));
    setMaxLength();
    curLength++;
    growCount++;
}

void Snake::eatPoisonItem() {
    snakePos.pop_back();
    curLength--;
    poisonCount++;
}

void Snake::setCurLength() {
    curLength = getLength();
}