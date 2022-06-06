#include <stdio.h>
#include <stdlib.h>

int size=0;

int gcd(int a, int b){
    if (b==0) {
        return a;
    }
    return gcd(b, a%b);
}

int lcm(int a, int b){
    return (a*b)/gcd(a, b);
}

int *arrayDigits(int *arr,int c){
    int *arr1=(int*)malloc(100* sizeof(int));
    int i=0;
    while (c>0) {
        arr1[i]=c%10;
        c/=10;
        i++;
        size++;
    }
    int k=0;
    for (int j=size-1; j>=0; j--) {
        arr[k]=arr1[j];
        if (k<size-1) {
            k++;
        }
    }return arr;
}

int main(int argc, const char * argv[]) {
    printf("Task 1: ");
    printf("\nEnter first natural number: ");
    int a; scanf("%d",&a);
    printf("Enter second natural number: ");
    int b; scanf("%d",&b);
    printf("Greatest common divisor of %d and %d: %d",a,b,gcd(a, b));
    printf("\nLeast common multiple of %d and %d: %d",a,b,lcm(a, b));
    
    printf("\nTask 2:");
    printf("\nEnter 1 natural number: ");
    int c; scanf("%d",&c);
    int *arr=(int*)malloc(100* sizeof(int));
    arr=arrayDigits(arr, c);
    printf("\nResults: ");
    for (int i=0; i<size; i++) {
        printf("%5d", arr[i]);
    }printf("\n");
    return 0;
}
