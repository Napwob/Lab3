#include "text.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void attention()
{
    printf("Please, enter 'circle(x,y,r)'\n");
}

void attention1()
{
    printf("Please, enter the next'circle(x,y,r)'\n");
}

void type(int x, int y, int r, double s, double p)
{
    printf("\nType of Figure: circle\n");
    printf("%d - X\n%d - Y\n%d - R\n", x, y, r);
    printf("Area = %.4f\n", s);
    printf("Perimeter= %.4f\n", p);
}

void error()
{
    printf("Error: unknown shape/shapes or wrong coordinates\n");
}

int rtext(char* h)
{
    int errortext = 0;
    int i;
    char f1[] = {"circle"};
    for (i = 0; i < 6; i++) {
        if (h[i] != f1[i])
            errortext++;
    }
    return errortext;
}

double fsp(int g, int r)
{
    if (g = 1)
        return s = r * r * M_PI;
    else
        return p = 2 * M_PI * r;
}

int rnumber(char* h)
{
    int errornumber = 0;
    int i = 6;
    while (1) {
        if (h[i] == ',' || h[i] == '(' || h[i] == ')') {
            errornumber++;
        }
        i++;
        if (h[i] == '\0')
            break;
    }
    return errornumber;
}

int ati(int x, int y, int r, int x1, int y1, int r1)
{
    int sqr;
    if (x == x1 && y == y1 && r == r1) {
        return 0;
        exit(1);
    }
    r += r1;
    x = abs(x - x1);
    y = abs(y - y1);
    x = pow(x, 2);
    y = pow(y, 2);
    sqr = sqrt(x + y);
    if (sqr <= r) {
        return 0;
    } else {
        return 1;
    }
}