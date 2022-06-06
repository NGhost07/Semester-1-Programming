#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* set_time_in_string(struct tm *infor){
    char *s = (char*)malloc(50*sizeof(char));
    strftime(s, 50, "%a %d.%b.%Y %I:%M:%S %p", infor);
    return s;
}

int main(int argc, char *argv[]){
    FILE *fout = fopen("myfile.out", "w");
    char *result[10];
    time_t time_now = time(NULL);
    struct tm *infor = localtime(&time_now);
    
    result[0] = set_time_in_string(infor);
    for (int i = 1; i < 10; i++){
        infor->tm_mday += 1;
        time_t next = mktime(infor);
        infor = localtime(&next);
        char *s=(char*)malloc(50*sizeof(char));
        s = set_time_in_string(infor);
        result[i] = s;
    }
    for (int i = 0; i < 10; i++){
        fputs(result[i], fout);
        fprintf(fout, "\n");
    }
    fclose(fout);
    return 0;
}
