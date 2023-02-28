#if !defined(BALL_HPP)
#define BALL_HPP

class ball //Ball
{
protected:
    int x, y, r;
    int point;
    char letter;

public:
    ball(int, int, int);
    virtual void draw() = 0;
    virtual void undraw() = 0;
    void setPoint(int);
    void setPosition(int, int);
    int getX() const;
    int getY() const;
    int getPoint() const;
    void setletter(char);
    void set(int, int, int);
    void setY(int);
    void move(int);
    char getletter() const;
};

#endif // BALL_HPP