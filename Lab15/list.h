#include <stdlib.h>
#include <stdio.h>
#define bool unsigned char
#define false 0
#define true 1
#ifndef list_h
#define list_h

bool file_exists(char * FileName){
        FILE * F = fopen(FileName,"rb");
        if (!F) return false;
        fclose(F);
        return true;
}

typedef struct HEADER{
        char filename[32];
        int tablesize;
        int datasize;
} Header;

unsigned char* source;
long sourceLen;
unsigned char* target;
long targetLen;
unsigned char* table;
long tableLen;

void freeSource(){
    if (sourceLen) free(source);
    sourceLen = 0;
    source = NULL;
}
void freeTarget(){
    if (tableLen) free(table);
    table = NULL;
    tableLen = 0;
    if (targetLen) free(target);
    target = NULL;
    targetLen = 0;
}

void Compress(){
        freeTarget();
        target = malloc(sourceLen);
        targetLen = sourceLen;
        memcpy(target,source,targetLen);
        tableLen = 0;
}

void extract(){
        freeSource();
        source = malloc(targetLen);
        sourceLen = targetLen;
        memcpy(source,target,sourceLen);
}

#endif
