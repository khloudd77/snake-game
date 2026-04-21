#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"

class Game {
private:
    int width, height;
    int score;
    bool gameOver;
    int dir;

    Snake snake;
    Food food;

public:
    Game();
    void setup();
    void draw();
    void input();
    void logic();
    void run();
};

#endif