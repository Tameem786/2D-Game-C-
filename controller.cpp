#include "controller.hpp"
#include <iostream>
#include <graphics.h>

controller::controller() { Ball = NULL; }

void controller::setBall(ball *b)
{
    Ball = b;
}

void controller::addPoint(int p)
{
    Ball->setPoint(p);
}

void controller::minusPoint(int q)
{
    Ball->setPoint(-1 * q);
}

void controller::showBall()
{
    Ball->draw();
}

void controller::hideBall()
{
    Ball->undraw();
}

void controller::setPos(int _x, int _y)
{
    Ball->setPosition(_x, _y);
}

int controller::getX() const { return Ball->getX(); }

int controller::getY() const { return Ball->getY(); }

int controller::showPoint()
{
    return Ball->getPoint();
}

void controller::setLetter(char l)
{
    Ball->setletter(l);
}

void controller::move(int dy)
{
    Ball->move(dy);
}

void controller::setY(int _y)
{
    Ball->setY(_y);
}

char controller::getLetter() const
{
    return Ball->getletter();
}

int controller::getPoint() const
{
    return Ball->getPoint();
}