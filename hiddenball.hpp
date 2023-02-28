#if !defined(HIDDENBALL_HPP)
#define HIDDENBALL_HPP
#include "ball.hpp"

class hiddenball : public ball
{
public:
    hiddenball(int, int, int);
    void draw();
    void undraw();
};

#endif // HIDDENBALL_HPP