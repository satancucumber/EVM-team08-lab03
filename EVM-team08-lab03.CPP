#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <string.h>

double f(double x)  /*f(x) = Sin^3(x)+ Cos^2(x)*/
{
    double y;
    y = (pow(sin(x * M_PI / 180), 3)) + (pow(cos(x * M_PI / 180), 2));
    return -y;
}

int main(void)
{
    /* request auto detection */
    int i;
    double midx , midy, x1, y1, x2, y2, K, N, j;
    char numbers[41][4];
    int gdriver = DETECT, gmode, errorcode;

    strcpy(numbers[0], "-10\0");
    strcpy(numbers[1], "-9\0");
    strcpy(numbers[2], "-8\0");
    strcpy(numbers[3], "-7\0");
    strcpy(numbers[4], "-6\0");
    strcpy(numbers[5], "-5\0");
    strcpy(numbers[6], "-4\0");
    strcpy(numbers[7], "-3\0");
    strcpy(numbers[8], "-2\0");
    strcpy(numbers[9], "-1\0");
    strcpy(numbers[10], "0\0");
    strcpy(numbers[11], "1\0");
    strcpy(numbers[12], "2\0");
    strcpy(numbers[13], "3\0");
    strcpy(numbers[14], "4\0");
    strcpy(numbers[15], "5\0");
    strcpy(numbers[16], "6\0");
    strcpy(numbers[17], "7\0");
    strcpy(numbers[18], "8\0");
    strcpy(numbers[19], "9\0");
    strcpy(numbers[20], "10\0");
    strcpy(numbers[21], "11\0");
    strcpy(numbers[22], "12\0");
    strcpy(numbers[23], "13\0");
    strcpy(numbers[24], "14\0");
    strcpy(numbers[25], "15\0");
    strcpy(numbers[26], "16\0");
    strcpy(numbers[27], "17\0");
    strcpy(numbers[28], "18\0");
    strcpy(numbers[29], "19\0");
    strcpy(numbers[30], "20\0");
    strcpy(numbers[31], "21\0");
    strcpy(numbers[32], "22\0");
    strcpy(numbers[33], "23\0");
    strcpy(numbers[34], "24\0");
    strcpy(numbers[35], "25\0");
    strcpy(numbers[36], "26\0");
    strcpy(numbers[37], "27\0");
    strcpy(numbers[38], "28\0");
    strcpy(numbers[39], "29\0");
    strcpy(numbers[40], "30\0");



    K = 25;
    N = 2.5;
    /* initialize graphics and local variables */
    initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");

    /* read result of initialization */
    errorcode = graphresult();
    if (errorcode != grOk)  /* an error occurred */
    {
    printf("Graphics error: %s\n", grapherrormsg(errorcode));
    printf("Press any key to halt:");
    getch();
    exit(1); /* terminate with an error code */
    }

    setcolor(getmaxcolor());

    midx = 0;
    midy = getmaxy() / 2;

    setbkcolor(3);
    //line(5, 5, getmaxx() - 5, 5);
    //line(5, 5, 5, getmaxy() - 5);
    //line(getmaxx() - 5, 5, getmaxx() - 5, getmaxy() - 5);
    //line(5, getmaxy() - 5, getmaxx() - 5, getmaxy() - 5);

    line(0, midy, 0 + 1000, midy);  /*OX*/
    line(20, 1000, 20, midy - 1000);  /*OY*/

    //outtextxy(10, midy + 5, "0");

    j = -f(90) * K;

    for (i = -10; i < 30; i++)
    {
        line(17, midy + i*j, 23, midy + i*j);
        if (i <= 0) outtextxy(17 - 5, midy + i*j + 3, numbers[10 - i]);
        else outtextxy(17 - 15, midy + i*j + 3, numbers[10 - i]);

        line(20 + i*j, midy + 3, 20 + i*j, midy - 3);
        if (i != 0) outtextxy(20 + i*j + 3, midy - 3 + 5, numbers[i + 10]);
    }

    x1 = 270;
    y1 = f(x1);

    for (x2 = x1; x2 <= 1440; x2++)   /*start = (3*M_PI)/2 ; end = 8*M_PI */
    {
	y2 = f(x2);
	line(midx + x1 / N + 20, midy + y1 * K, midx + x2 / N + 20, midy + y2 * K);
	x1 = x2;
	y1 = y2;
	delay(10);
    }
    moveto(20, 20);
    printf("Maximum value: 1");
    /* clean up */
    getch();
    closegraph();
    return 0;
}