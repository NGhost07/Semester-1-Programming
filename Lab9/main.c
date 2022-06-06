#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countNumber(char *s){
    int count=0;
    for (int i=0;i<strlen(s);i++)
        if (s[i]>=48 && s[i]<=57)
            count++;
return count;
}

int countLowercase(char *s){
    int count=0;
    for (int i=0;i<strlen(s);i++)
        if (s[i]>=97 && s[i]<=122)
            count++;
return count;
}

int countUppercase(char *s){
    int count=0;
    for (int i=0;i<strlen(s);i++)
        if (s[i]>=65 && s[i]<=90)
            count++;
return count;
}

void lineDigit(char *s){
    char *s1 = (char*)malloc(200*sizeof(char));
    int j=0;
    for (int i=0; i<strlen(s); i++) {
        if (s[i]>=48 && s[i]<=57) {
            s1[j]=s[i];
            j++;
        }
    }
    puts(s1);
}

int main(int argc, const char * argv[]) {
    char *s = (char*)malloc(200*sizeof(char));
    printf("Enter 1 line: \n");
    std:fflush(stdin);
    fgets(s, 200, stdin);
    
    printf("\nTask 1: ");
    printf("\nIn this line have %d numeric characters.\n", countNumber(s));
    printf("\nIn this line have %d lowercase letters.\n", countLowercase(s));
    printf("\nIn this line have %d uppercase letters.\n", countUppercase(s));

    printf("\nTask 3: ");
    printf("\nThis is line number: ");
    lineDigit(s);
    printf("\n");
    free(s);
    return 0;
}
