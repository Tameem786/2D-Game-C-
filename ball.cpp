#include "ball.hpp"
#include <iostream>
#include <graphics.h>

ball::ball(int _x = 0, int _y = 0, int _r = 0) : x(_x), y(_y), r(_r)
{
    point = 0;
}

void ball::setPosition(int _x, int _y)
{
    x = _x;
    y = _y;
}

void ball::setPoint(int _point)
{
    point = point + _point;
}

int ball::getX() const { return x; }

int ball::getY() const { return y; }

int ball::getPoint() const { return point; }

void ball::setletter(char l)
{
    letter = l;
}

void ball::set(int _x, int _y, int _r)
{
    x = _x;
    y = _y;
    r = _r;
}

void ball::setY(int _y)
{
    y = _y;
}

void ball::move(int dy)
{
    y = y + dy;
}

char ball::getletter() const
{
    return letter;
}
