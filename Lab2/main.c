#include <stdio.h>
#include <math.h>

double calculateZ1(double x){ // 8 byte ~ 2.3E-308 to 1.7E+308
    double z1=0; //8 byte ~  2.3E-308 to 1.7E+308
    z1 = (pow(x, 2) + 2*x - 3 + (x+1)* sqrt(pow(x, 2)-9)) /
         (pow(x, 2) - 2*x - 3 + (x-1)* sqrt(pow(x, 2)-9));
    return z1;
}

double calculateZ2(double x){//8 byte ~ 2.3E-308 to 1.7E+308
    double z2=0; //8 byte ~ 2.3E-308 to 1.7E+308
    z2 = sqrt((x+3)/(x-3));
    return z2;
}

int main(){
    double x;//8 byte ~ 2.3E-308 to 1.7E+308
    printf("Enter x : "); scanf("%lf",&x);
    printf("Z1 = %lf\n", calculateZ1(x));
    printf("Z2 = %lf\n", calculateZ2(x));

    return 0;
}
