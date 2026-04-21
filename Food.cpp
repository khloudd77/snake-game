#include <cstdlib>
#include "Food.h"

void Food::generate(int width, int height) {
    x = rand() % width;
    y = rand() % height;
}

int Food::getX() { return x; }
int Food::getY() { return y; }  