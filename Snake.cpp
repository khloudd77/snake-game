#include "Snake.h"

Snake::Snake() {
    x = 10;
    y = 10;
    length = 0;
}

void Snake::updateTail() {
    for (int i = length; i > 0; i--) {
        tailX[i] = tailX[i - 1];
        tailY[i] = tailY[i - 1];
    }
    tailX[0] = x;
    tailY[0] = y;
}

void Snake::move(int dir) {
    updateTail();

    switch (dir) {
    case 1: x--; break;
    case 2: x++; break;
    case 3: y--; break;
    case 4: y++; break;
    }
}

void Snake::grow() {
    length++;
}

int Snake::getX() { return x; }
int Snake::getY() { return y; }
int* Snake::getTailX() { return tailX; }
int* Snake::getTailY() { return tailY; }
int Snake::getLength() { return length; }