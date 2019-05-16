#include "func.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

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

int main()
{
    int x, y, r, errortext, errornumber, at;
    int x1, y1, r1, errortext1, errornumber1;
    char h[20] = "", h1[20] = "";
    double s, p;
    double s1, p1;
    int i = 7;
    while (1) {
        errortext = 0;
        errornumber = 0;
        attention();
        cin >> h;

        errortext1 = 0;
        errornumber1 = 0;
        attention1();
        cin >> h1;

        errortext = rtext(h);
        errornumber = rnumber(h);

        if (errortext == 0 && errornumber == 4) {
            x = readin(h, i, ',');
            y = readin(h, i, ',');
            r = readin(h, i, ')');
        }
        errortext1 = rtext(h1);
        errornumber1 = rnumber(h1);

        if (errortext1 == 0 && errornumber1 == 4) {
            i = 7;
            x1 = readin(h, i, ',');
            y1 = readin(h, i, ',');
            r1 = readin(h, i, ')');
        }
        if ((errortext == 0 && x != 0 && y != 0 && r != 0 && errornumber == 4
             && errortext1 == 0)
            && (x1 != 0 && y1 != 0 && r1 != 0 && errornumber1 == 4)) {
            s = fsp(1, r);
            p = fsp(0, r);
            s1 = fsp(1, r1);
            p1 = fsp(0, r1);
            type(x, y, r, s, p);
            type(x1, y1, r1, s1, p1);
            at = ati(x, y, r, x1, y1, r1);
            if (at == 0)
                printf("\nFigures cross each other\n");
            else
                printf("\nFigures not cross each other\n");
        } else {
            error();
        }
    }
}
