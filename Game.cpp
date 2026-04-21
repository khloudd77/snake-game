#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Game.h"

using namespace std;

Game::Game() {
    width = 20; height = 20;
    score = 0; gameOver = false; 
    dir = 0; // 0 يعني STOP، التعبان هيفضل واقف مكانه لحد ما تلعبي
}

void Game::setup() { 
    food.generate(width, height); 
}

void Game::draw() {
    // الكود ده بيمسح "الذاكرة" بتاعة الشاشة ويرجع المؤشر لفوق خالص
    // ده بيمنع الرعشة وبيمنع تكرار الهاش (#) فوق
    COORD cursorPosition;	
    cursorPosition.X = 0;	
    cursorPosition.Y = 0;	
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);  

    // رسم السطر اللي فوق
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "#"; // الحيطة الشمال

            if (i == snake.getY() && j == snake.getX())
                cout << "O"; // رأس التعبان
            else if (i == food.getY() && j == food.getX())
                cout << "F"; // الأكل
            else {
                bool print = false;
                for (int k = 0; k < snake.getLength(); k++) {
                    if (snake.getTailX()[k] == j && snake.getTailY()[k] == i) {
                        cout << "o"; // جسم التعبان
                        print = true;
                    }
                }
                if (!print) cout << " ";
            }

            if (j == width - 1) cout << "#"; // الحيطة اليمين
        }
        cout << endl;
    }

    // رسم السطر اللي تحت
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    // مساحة للمعلومات (الفرغات دي عشان تمسح أي كلام قديم)
    cout << "Score: " << score << "   " << endl; 
    cout << "Press X to Exit | W,A,S,D to move   " << endl;
}
void Game::input() {
    if (_kbhit()) {
        char key = _getch();
        // السطر ده عشان نتأكد إن البرنامج لقط الزرار
        // لو دوستي D والسرعة بدأت تتغير أو الاتجاه اتغير يبقى شغال
        switch (key) {
            case 'a': dir = 1; break;
            case 'd': dir = 2; break;
            case 'w': dir = 3; break;
            case 's': dir = 4; break;
            case 'x': gameOver = true; break;
        }
    }
}

void Game::logic() {
    if (dir == 0) return; // لو الاتجاه 0 متمشيش، استنى اللاعب

    snake.move(dir);

    // لو خبط في الحيطة
    if (snake.getX() >= width || snake.getX() < 0 || snake.getY() >= height || snake.getY() < 0)
        gameOver = true;

    // لو خبط في جسمه
    for (int i = 0; i < snake.getLength(); i++)
        if (snake.getTailX()[i] == snake.getX() && snake.getTailY()[i] == snake.getY())
            gameOver = true;

    // لو أكل
    if (snake.getX() == food.getX() && snake.getY() == food.getY()) {
        score += 10;
        snake.grow();
        food.generate(width, height);
    }
}

void Game::run() {
    setup();
    // إخفاء الكيرسور اللي بيفضل يرعش
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(150); // سرعة هادية ومريحة
    }
    system("cls");
    cout << "Game Over! Score: " << score << endl;
}