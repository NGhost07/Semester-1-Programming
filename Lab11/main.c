#include <stdio.h>
#include <math.h>
#include "functions.h"

int main() {
    struct point p1,p2,p3;
    printf("=== Perimeter and Square of triangle ===");
    printf("\nEnter point A coordinates:");
    printf("\nxA = "); scanf("%d", &p1.x);
    printf("yA = "); scanf("%d", &p1.y);
    printf("\nEnter point B coordinates:");
    printf("\nxB = "); scanf("%d", &p2.x);
    printf("yB = "); scanf("%d", &p2.y);
    printf("\nEnter point C coordinates:");
    printf("\nxC = "); scanf("%d", &p3.x);
    printf("yC = "); scanf("%d", &p3.y);
    struct triangle A = Triangle(p1, p2, p3);
    printf("\nPerimeter: %lf", perimeter(A));
    printf("\nSquare: %lf", square(A));
    printf("\n");
    return 0;
}
