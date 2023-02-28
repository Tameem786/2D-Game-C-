#if !defined(BLUEBALL_HPP)
#define BLUEBALL_HPP
#include "ball.hpp"

class blueball : public ball
{
public:
    blueball(int, int, int);
    void draw();
    void undraw();
};

#endif // BLUEBALL_HPP