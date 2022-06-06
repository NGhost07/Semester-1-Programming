#ifndef functions_h
#define functions_h
#include <stdio.h>
#include <math.h>

struct point {
    int x;
    int y;
};

struct triangle{
    double a;
    double b;
    double c;
};

double triangleSideLength(struct point p1, struct point p2);

struct triangle Triangle(struct point p1, struct point p2, struct point p3);

double perimeter(struct triangle Triangle);

double square(struct triangle Triangle);
#endif
