#include "text.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void attention()
{
    printf("Please, enter 'circle(x,y,r)'\n");
}

void attention1()
{
    printf("Please, enter 'circle(x,y,r)'\n");
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

int readin(char* h, int& i, char el)
{
    int k = 0, coor;
    char ch[100];
    memset(ch, 0, sizeof(ch));
    while (h[i] != el) {
        ch[k] = h[i];
        k++;
        i++;
    }
    coor = atoi(ch);
    i = i + 1;
    return coor;
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

void coor(int& x, int& y, int& r, char* h)
{
    int i = 7;
    x = readin(h, i, ',');
    y = readin(h, i, ',');
    r = readin(h, i, ')');
}

void fsp(double& s, double& p, int r)
{
    s = r * r * M_PI;
    p = 2 * M_PI * r;
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
        if (h[i] == " ")
            break;
    }
    return errornumber;
}

void ati(int x, int y, int r, int x1, int y1, int r1)
{
    int sqr;
    if (x == x1 && y == y1) {
        printf("\nAnd they are crossing itself's\n");
        exit(1);
    }
    r += r1;
    x = abs(x - x1);
    y = abs(y - y1);
    x = pow(x, 2);
    y = pow(y, 2);
    sqr = sqrt(x + y);
    if (sqr <= r)
        printf("\nAnd they are crossing itself's\n");
    else
        printf("\nAnd they aren't crossing itself's\n");
    printf("x-%d y-%d sqr- %d\n r -%d", x, y, sqr, r);
}
