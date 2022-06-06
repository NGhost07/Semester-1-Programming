#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int size(char *s){
    int a=0, sizeS=0;
    while (s[a]!='\0') {
        sizeS++;
        a++;
    }return sizeS;
}

int compareSize(int a, int b){
    if (a>b) {
        return 1;
    }else if (a<b){
        return -1;
    }else{
        return 0;
    }
}

void cat(char *s1, char *s2){
    char *s = (char*)malloc(200*sizeof(char));
    int sizeS1 = size(s1);
    printf("Enter number n initial characters of the second line: ");
    int n; scanf("%d",&n);
    for (int i=0; i<sizeS1; i++) {
        s[i] = s1[i];
    }
    int k=0;
    int j;
    for (j=sizeS1-1; j<sizeS1-1+n; j++) {
        s[j] = s2[k];
        k++;
    }s[j]='\0';
    printf("\nResult after add: ");
    puts(s);
}

int compare(char *s1, char *s2){
    int sizeS1 = size(s1);
    int sizeS2 = size(s2);
    if (compareSize(sizeS1, sizeS2)==1) {
        for (int i=0; i<sizeS2; i++) {
            if (s1[i]>s2[i]) {
                return 1; // s1 > s2
            }
            if (s1[i]<s2[i]) {
                return -1; // s1 < s2
            }
        }
        if (compareSize(sizeS1, sizeS2) == 1) {
            return 1;
        }else if (compareSize(sizeS1, sizeS2) == -1){
            return -1;
        }
    }
    if (compareSize(sizeS1, sizeS2)==-1) {
        for (int i=0; i<sizeS1; i++) {
            if (s1[i]>s2[i]) {
                return 1; // s1 > s2
            }
            if (s1[i]<s2[i]) {
                return -1; // s1 < s2
            }
        }
        if (compareSize(sizeS1, sizeS2) == 1) {
            return 1;
        }else if (compareSize(sizeS1, sizeS2) == -1){
            return -1;
        }
    }
    return 0; // s1 = s2
}

char copy(int n, char *s1, char *s2){
    int i=0;
    for (i=0; i<n; i++) {
        s2[i] = s1[i];
    }s2[i] = '\0';
    return *s2;
}

void seach(char *s, char a){
    int b=0;
    for (int i=size(s); i>=0; i--) {
        if (s[i]==a) {
            b=i;
            break;
        }else{
            b=-1;
        }
    }
    if (b==-1) {
        printf("Does not appear %c in the array",a);
    }else{
        for (int i=b; i<=size(s); i++) {
            printf("%c",s[i]);
        }
    }
}

int length(char *s1, char *s2){
    for (int i=0; i<size(s1); i++) {
        for (int j=0; j<size(s2); j++) {
            if (s1[i]==s2[j]) {
                return i;
            }
        }
    }return 0;
}

int main() {
    char *s1 = (char*)malloc(200*sizeof(char));
    char *s2 = (char*)malloc(100*sizeof(char));
    printf("Enter first line: \n");
    std:fflush(stdin);
    fgets(s1, 100, stdin);
    printf("Enter second line: \n");
    fgets(s2, 100, stdin);
    
    printf("\nTask 2: ");
    printf("\n");
    cat(s1, s2);
    
    printf("\nTask 3: ");
    if (compare(s1, s2)==1) {
        printf("\nFist line > Second line");
    }else if(compare(s1, s2)== -1){
        printf("\nFist line < Second line");
    }else{
        printf("\nFist line = Second line");
    }
    
    printf("\n\nTask 6: ");
    char *s = (char*)malloc(200*sizeof(char));
    printf("\nEnter first n characters of one line: ");
    int a; scanf("%d",&a);
    *s = copy(a, s1,s);
    printf("Copy the first %d characters of firt line: ",a);
    puts(s);
    
    printf("\nTask 9: ");
    printf("\nEnter symbol: ");
    fflush(stdin);
    char b = getchar();
    printf("Result: ");
    seach(s1, b);
    
    printf("\nTask 12: ");
    printf("\nLength of a segment of first line that doesn't contain the characters of the second line: %d", length(s1, s2));
    printf("\n");
    return 0;
}
