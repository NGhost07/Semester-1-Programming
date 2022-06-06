#include <stdio.h>

void print(int a[2][2]){
    for (int i=0; i<2; i++) {
        printf("\n");
        for (int j=0; j<2; j++) {
            printf("%5d", a[i][j]);
        }
    }
}

int main(int argc, const char * argv[]) {
    printf("Task 1:\nThis is your array: \n");
    int x[6] = {34,45,56,67,78,89};
    for (int i=0; i<6; i++) {
        printf("%10d", x[i]);
    }
    printf("\n");
    
    printf("Task 2:\nThis is the multiplication of two matrices:\n");
    int a[2][2] = {2,1,1,3};
    int b[2][2] = {1,2,3,1};
    int result[2][2];
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            result[i][j] = 0;
            for (int k=0; k<2; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    print(a);
    printf("\tx\t\n");
    print(b);
    printf("\t=\t\n");
    print(result);
    printf("\n");
    return 0;
}
