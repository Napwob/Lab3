#include "func.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct coor {
    int x, y, r;
};

struct coor readcr(char* h)
{
    int k = 0;
    char chx[3] = "";
    struct coor h1;
    int i = 7;
    while (h[i] != ',') {
        chx[k] = h[i];
        k++;
        i++;
    }
    h1.x = atoi(chx);
    i = i + 1;
    char chy[3] = "";
    k = 0;
    while (h[i] != ',') {
        chy[k] = h[i];
        k++;
        i++;
    }
    h1.y = atoi(chy);
    i = i + 1;
    char chr[3] = "";
    k = 0;
    while (h[i] != ')') {
        chr[k] = h[i];
        k++;
        i++;
    }
    h1.r = atoi(chr);
    return h1;
}

char* cin()
{
    int i = 0;
    char h[20] = " ";
    char* a = h;
    char c;
    while ((c = getchar()) != '\n') {
        h[i] = c;
        i++;
    }
    return a;
}

int main()
{
    int errortext, errornumber, at;
    int errortext1, errornumber1;
    struct coor h2;
    struct coor h0;
    char h[20] = "", h1[20] = "";
    double s, p;
    double s1, p1;
    while (1) {
        errortext = 0;
        errornumber = 0;
        attention();
        scanf("%s", h);
        if (h[0] == 'z')
            return 0;
        errortext1 = 0;
        errornumber1 = 0;
        attention1();
        scanf("%s", h1);
        if (h[0] == 'z')
            return 0;
        errortext = rtext(h);
        errornumber = rnumber(h);

        if (errortext == 0 && errornumber == 4) {
            h0 = readcr(h);
        }
        errortext1 = rtext(h1);
        errornumber1 = rnumber(h1);

        if (errortext1 == 0 && errornumber1 == 4) {
            h2 = readcr(h1);
        }
        if ((errortext == 0 && h0.x != 0 && h0.y != 0 && h0.r != 0
             && errornumber == 4 && errortext1 == 0)
            && (h2.x != 0 && h2.y != 0 && h2.r != 0 && errornumber1 == 4)) {
            s = fsp(1, h0.r);
            p = fsp(0, h0.r);
            s1 = fsp(1, h2.r);
            p1 = fsp(0, h2.r);
            type(h0.x, h0.y, h0.r, s, p);
            type(h2.x, h2.y, h2.r, s1, p1);
            at = ati(h0.x, h0.y, h0.r, h2.x, h2.y, h2.r);
            if (at == 0)
                printf("\nFigures cross each other\nIf you want to exit print "
                       "'Z' instead of 'circle(x,y,z)'\n\n");

            else
                printf("\nFigures not cross each other\nIf you want to exit "
                       "print 'Z' instead of 'circle(x,y,z)'\n\n");
        } else {
            error();
        }
    }
}
