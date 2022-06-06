#include "functions.h"

double triangleSideLength(struct point p1, struct point p2){
    return sqrt((double)pow(p2.x-p1.x, 2)+pow(p2.y-p1.y, 2));
}

struct triangle Triangle(struct point p1, struct point p2, struct point p3){
    struct triangle Triangle;
    Triangle.a = triangleSideLength(p1, p2);
    Triangle.b = triangleSideLength(p1, p3);
    Triangle.c = triangleSideLength(p2, p3);
    return  Triangle;
}

double perimeter(struct triangle Triangle){
    double P = Triangle.a + Triangle.b + Triangle.c;
    return P;
}

double square(struct triangle Triangle){
    double P = (Triangle.a + Triangle.b + Triangle.c)/2;
    double S = sqrt(P*(P-Triangle.a)*(P-Triangle.b)*(P-Triangle.c));
    return S;
}
