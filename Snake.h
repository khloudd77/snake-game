#ifndef SNAKE_H
#define SNAKE_H

class Snake {
private:
    int x, y;
    int tailX[100], tailY[100];
    int length;

public:
    Snake();
    void move(int dir);
    void grow();
    void updateTail();
    int getX();
    int getY();
    int* getTailX();
    int* getTailY();
    int getLength();
};

#endif