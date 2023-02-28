#include "blueball.hpp"
#include <iostream>
#include <graphics.h>

blueball::blueball(int _x = 0, int _y = 0, int _r = 0) : ball(_x, _y, _r) {}

void blueball::draw()
{
    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    fillellipse(x, y, r, r);
    settextstyle(10, HORIZ_DIR, 3);
    setbkcolor(BLUE);
    setcolor(WHITE);
    bgiout << letter;
    outstreamxy(x - 5, y - 8);
}

void blueball::undraw()
{
    setfillstyle(SOLID_FILL, WHITE);
    setcolor(WHITE);
    fillellipse(x, y, r, r);
}