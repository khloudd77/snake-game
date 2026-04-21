#ifndef FOOD_H
#define FOOD_H

class Food {
private:
    int x, y;

public:
    void generate(int width, int height);
    int getX();
    int getY();
};

#endif