#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "text.h"

using namespace std;

int main()
{
    int x, y, r, errortext, errornumber;
    int x1, y1, r1, errortext1, errornumber1;
    char h[20] = "", h1[20] = "";
    double s, p;
    double s1, p1;
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

        if (errortext == 0 && errornumber == 4)
            coor(x, y, r, h);

        errortext1 = rtext(h1);
        errornumber1 = rnumber(h1);

        if (errortext1 == 0 && errornumber1 == 4)
            coor(x1, y1, r1, h1);

        //printf("\nt - %d n - %d\n",errortext1,errornumber1);
        if (errortext == 0 && x != 0 && y != 0 && r != 0 && errornumber == 4 && errortext1 == 0 && x1 != 0 && y1 != 0 && r1 != 0 && errornumber1 == 4) {
            fsp(s, p, r);
            fsp(s1, p1, r1);
            type(x, y, r, s, p);
            type(x1, y1, r1, s1, p1);
            ati(x, y, r, x1, y1, r1);
            return 0;
        }
        else {
            error();
        }
    }
}
