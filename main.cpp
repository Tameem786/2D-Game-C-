#include <iostream>
#include <graphics.h>
#include <cstdlib>
#include "ball.hpp"
#include "blueball.hpp"
#include "hiddenball.hpp"
#include "controller.hpp"
#include <fstream>
#include <iomanip>

using namespace std;

int w = getmaxwidth();
int h = getmaxheight();
int main()
{
    fstream file;
    int x = 400, y = 30, r = 30;
    int time = 300;
    const int SIZE = 12;
    const int alphabateSize = 26;
    const int pos = 15;
    const int hideSize = 15;
    bool status = true;
    int number = 7;
    int barcolor = COLOR(194, 223, 246);
    int wordcolor = 15;
    int point = 0, p = 0;
    bool BluepointStatus, RedpointStatus;
    int charPosition[pos] = {3, 5, 7, 6, 3, 2, 8, 9, 7, 4, 11, 3, 6, 8, 5};
    string imageFile = "resources/b.jpg";
    string logoFile = "resources/logojpg.jpg";
    string soundFile = "resources/jump_sound.wav";
    string name;
    controller ctrl1[SIZE];
    controller ctrl2;
    hiddenball hide(x, y, r);
    blueball *b[SIZE];
    int speed[SIZE] = {13, 15, 17, 16, 13, 12, 18, 19, 17, 14, 11, 13};
    char letters[alphabateSize] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                                   'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    file.open("resources/record.txt", ios::out | ios::in | ios::app);

    cout << "Enter Your Name: ";
    cin >> name;

    initwindow(w, h, "Aplha Rain");

    for (int i = 0; i < SIZE; i++)
    {
        b[i] = new blueball(x, y, r);
        x = x + 2 * r + 30;
    }

    for (int i = 0; i < SIZE; i++)
        ctrl1[i].setBall(b[i]);

    ctrl2.setBall(&hide);

    while (1)
    {
        readimagefile(imageFile.c_str(), 350, 0, w, h);
        setfillstyle(SOLID_FILL, barcolor);
        setcolor(barcolor);
        bar(0, 0, 350, h);
        readimagefile(logoFile.c_str(), 50, 0, 300, 300);
        BluepointStatus = false;
        RedpointStatus = false;
        for (int i = 0; i < SIZE; i++)
        {
            if (i == number)
            {
                if (status)
                    ctrl2.setPos(ctrl1[i].getX(), 0);
                ctrl2.setLetter(ctrl1[i].getLetter());
                ctrl2.showBall();
                ctrl2.move(25);
                status = false;
                if (ctrl2.getY() > h - 10)
                {
                    number = (rand() % 10) + 1;
                    status = true;
                    charPosition[i] = (rand() % 25) + 1;
                }
            }
            else
            {
                ctrl1[i].setLetter(letters[charPosition[i]]);
                ctrl1[i].showBall();
                ctrl1[i].move(speed[i]);
                if (ctrl1[i].getY() > h - 10)
                {
                    ctrl1[i].setY(0);
                    charPosition[i] = (rand() % 25) + 1;
                }
            }
        }
        if (kbhit())
        {
            PlaySound(TEXT(soundFile.c_str()), NULL, SND_ASYNC);
            int ch = getch();
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 97; j <= 122; j++)
                {
                    if (ch == j)
                    {
                        if (ch == int(letters[charPosition[i]]) + 32)
                        {
                            ctrl1[i].setY(-60);
                            charPosition[i] = (rand() % 25) + 1;
                            BluepointStatus = true;
                            break;
                        }
                        if (ch == int(ctrl2.getLetter()) + 32)
                        {
                            ctrl2.setY(-60);
                            number = (rand() % 10) + 1;
                            status = true;
                            charPosition[i] = (rand() % 25) + 1;
                            RedpointStatus = true;
                            break;
                        }
                    }
                }
            }
            if (BluepointStatus)
                point++;
            if (RedpointStatus)
                point += 9;
        }

        setbkcolor(BLACK);
        setcolor(YELLOW);
        bgiout << name << "'s Score: " << point;
        outstreamxy(50, 400);

        setbkcolor(BLACK);
        setcolor(YELLOW);
        bgiout << "Time's Left: " << time << " sec";
        outstreamxy(50, 300);
        delay(50);
        time = time - 1;
        if (time == 0)
        {
            cleardevice();
            readimagefile(imageFile.c_str(), 350, 0, w, h);
            setfillstyle(SOLID_FILL, barcolor);
            setcolor(barcolor);
            bar(0, 0, 350, h);
            readimagefile(logoFile.c_str(), 50, 0, 300, 300);
            file << name << " " << point << endl;

            setfillstyle(SOLID_FILL, 12);
            setcolor(12);
            bar(700, 300, 1300, 500);
            settextstyle(10, HORIZ_DIR, 5);
            setbkcolor(12);
            setcolor(BLACK);
            bgiout << "GAME OVER" << endl;
            bgiout << "Your Score: " << point << endl;
            bgiout << "Press any key to exit";
            outstreamxy(750, 350);
            file.seekg(0, ios::beg);
            bgiout << "--------------------------" << endl;
            bgiout << setw(10) << "Name"
                   << "         " << setw(3) << "Score" << endl;
            bgiout << "--------------------------" << endl;
            while (file)
            {
                file >> name;
                file >> point;
                settextstyle(10, HORIZ_DIR, 1);
                setbkcolor(barcolor);
                setcolor(BLUE);
                bgiout << setw(10) << name << "         " << setw(3) << point << endl;
            }
            outstreamxy(50, 350);

            if (getch())
                break;
        }
    }

    for (int i = 0; i < SIZE; i++)
        delete b[i];

    file.close();
    getch();
    closegraph();
}
