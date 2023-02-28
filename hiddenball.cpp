#include "hiddenball.hpp"
#include <iostream>
#include <graphics.h>

hiddenball::hiddenball(int _x = 0, int _y = 0, int _r = 0) : ball(_x, _y, _r) {}

void hiddenball::draw()
{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(x, y, r, r);
    settextstyle(10, HORIZ_DIR, 3);
    setbkcolor(BLACK);
    setcolor(WHITE);
    bgiout << letter;
    outstreamxy(x - 5, y - 8);
}

void hiddenball::undraw()
{
    setfillstyle(SOLID_FILL, WHITE);
    setcolor(WHITE);
    fillellipse(x, y, r, r);
}