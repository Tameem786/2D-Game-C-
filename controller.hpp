#if !defined(CONTROLLER_HPP)
#define CONTROLLER_HPP
#include "ball.hpp"

class controller
{
protected:
    ball *Ball;

public:
    controller();
    void addPoint(int);
    void minusPoint(int);
    void setBall(ball *);
    int showPoint();
    void showBall();
    void hideBall();
    void setPos(int, int);
    int getX() const;
    int getY() const;
    void setLetter(char);
    void move(int);
    void setY(int);
    char getLetter() const;
    int getPoint() const;
};

#endif // CONTROLLER_HPP