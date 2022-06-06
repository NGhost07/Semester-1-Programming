#include <stdio.h>
#include <math.h>

struct Circle{
    float radius;
    float x,y;
}circle;

union status{
    struct keyboard{
        unsigned numLock :1;
        unsigned capLock :1;
        unsigned scrollLock :1;
    }bits;
    unsigned int data;
};

int main(int argc, const char * argv[]) {
    printf("Task 1:\n");
    enum printMedia {book, magazine, newspaper};
    printf("Newspaper = %d\n", newspaper);
    
    printf("\nTask 2:\n");
    //struct Circle circle;
    printf("Enter radius: "); scanf("%f", &circle.radius);
    printf("Enter coordinater of center circle: ");
    scanf("%f%f", &circle.x, &circle.y);
    float perimeter;
    perimeter = circle.radius * 2 *M_PI;
    printf("Coordinater of center circler: (%f;%f)\n",circle.x,circle.y);
    printf("Radius of the circle: %f\n", circle.radius);
    printf("Perimeter of the circle: %f\n",perimeter);
    
    printf("\nTask 3:\n");
    union status Start;
    printf("Enter Hexadecimal number: "); scanf("%X", &Start.data);
    printf("\nDEVICE STATUS: \n");
    printf("\nNumLock: %s",(Start.bits.numLock)? "on":"off");
    printf("\nCapLock: %s",(Start.bits.capLock)? "on":"off");
    printf("\nScrollLock: %s",(Start.bits.scrollLock)? "on":"off");
    printf("\n\n");
    return 0;
}
