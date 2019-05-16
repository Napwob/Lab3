#ifndef TEXT_H
#define TEXT_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void attention();
void error();
void attention1();
void type(int x, int y, int r, double s, double p);
int readin(char* h, int& i, char el);
int rtext(char* h);
void coor(int& x, int& y, int& r, char* h);
double fsp(int g, int r);
int rnumber(char* h);
int ati(int x, int y, int r, int x1, int y1, int r1);

#endif
