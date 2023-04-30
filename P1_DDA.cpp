#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;


class dda
{
private:
    int x1, y1, x2, y2, shade;

public:

    dda() = delete;
    dda(int x1, int y1, int x2, int y2, int shade) : x1(x1), y1(y1), x2(x2), y2(y2), shade(shade) {}

    void getLine()
    {
        
        int window = initwindow(600,600,"");
        setcurrentwindow(window);
        setbkcolor(WHITE);
        cleardevice();
        

        double dx = x2 - x1;
        double dy = y2 - y1;

        double steps = max(abs(dx),abs(dy));

        double X_shift = dx / steps;
        double Y_shift = dy / steps;

        double x = x1;
        double y = y1;
        for (int i = 0; i <= steps; i++)
        {
            putpixel(round(x), round(y), shade);
            x += X_shift;
            y += Y_shift;
        }
        
    }

};

int main()
{
    dda l1(200,100,350,100,BLACK);
    dda l2(100,200,100,350,BLACK);
    dda l3(50,300,400,200,BLACK);
    dda l4(50,200,400,300,BLACK);
    dda l5(100,400,200,100,BLACK);
    dda l6(100,100,200,400,BLACK);
    l1.getLine();
    l2.getLine();
    l3.getLine();
    l4.getLine();
    l5.getLine();
    l6.getLine();

    getch();
    closegraph();
    return 0;
}
