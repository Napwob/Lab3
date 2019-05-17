#include "func.h"
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
    if (g == 1)
        return (r * r * M_PI);
    if (g == 0)
        return (2 * M_PI * r);
    return 0;
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
    double sqr;
    double x5, y5;
    if (x == x1 && y == y1 && r == r1) {
        return 0;
        exit(1);
    }
    r += r1;
    x5 = abs(x - x1);
    y5 = abs(y - y1);
    x5 = pow(x5, 2);
    y5 = pow(y5, 2);
    sqr = sqrt(x5 + y5);
    if (sqr <= r) {
        return 0;
    } else {
        return 1;
    }
}
