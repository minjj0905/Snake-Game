#include <iostream>
#include <vector>
#include <Snake.h>
using namespace std;

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
    return length;
}

void Snake::setFailed() {
    fail = true;
}