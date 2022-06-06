#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    printf("Task 1:\nThis is your array: \n");
    float arr[4];
    arr[0] = -3.4;
    arr[1] = 4.5;
    arr[2] = -5.6;
    arr[3] = 6.7;
    
    float *p = arr;
    for (int i=0; i<4; i++) {
        printf("%10.1f", *(p+i));
    }
    printf("\n");
    
    printf("Task 2:\n");
    float *arr2 = (float*)malloc(10*sizeof(float));
    printf("Please enter array: \n");
    for (int i=0; i<4; i++) {
        printf("arr2[%d]: ",i);
        scanf("%f",&arr2[i]);
    }
    printf("This is your array: \n");
    for (int i=0; i<4; i++) {
        printf("%10.1f", *(arr2+i));
    }
    free(arr2);
    printf("\n");
    return 0;
}
