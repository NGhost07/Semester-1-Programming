#include <stdio.h>
#include <string.h>

int main (){
    double a; //8 byte ~ 2.3E-308 to 1.7E+308
    char c; //1 byte ~ -128 to 127 or 0 to 255

    printf("Enter the real number: ");
    scanf("%lf",&a);
    
    fflush(stdin);
    printf("Please enter a symbol: ");
    c=getc(stdin);
    
    printf("This is your real number: ");
    printf("%lf ",a);
    
    printf("\nThis is your symbol: ");
    putc(c, stdout);
    printf("\n");
    return 0;
}
