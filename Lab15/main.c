#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "huffman.h"
#include <stdio.h>

bool CheckParameters(int argc,char* argv[]){
    if (argc<4) return false;
    if (strcmp(argv[1],"--file") != 0) return false;
    if (strcmp(argv[3],"--create")!= 0 &&strcmp(argv[3],"--extract")!= 0 && strcmp(argv[3],"--list")!= 0)
   return false;
   return true;
}

void Create(int argc,char* argv[], char* FileName){
    Header H;
    if (strcmp(argv[3],"--create")!=0)
        return;

    FILE * F = fopen(FileName,"wb+");
    printf("Pack to %s\n",FileName);
    for (int k=4; k<argc; k++){
        memset(H.filename,0,sizeof(H.filename));
        strcpy(H.filename,argv[k]);
        FILE * G = fopen(H.filename,"rb+");
        if (!G){
            printf("File not found %s\n",H.filename);
            continue;
        }
        fseek(G,0,SEEK_END);
        int size = (int)ftell(G);
        fseek(G,0,SEEK_SET);
        source = malloc(size);
        fread(source,1,size,G);
        fclose(G);

        sourceLen = size;
        Pack();
        if (sourceLen < targetLen+tableLen)
        Compress();
        H.datasize = (int)targetLen;
        H.tablesize = (int)tableLen;
        fwrite(&H,sizeof(H),1,F);
        if (tableLen) fwrite(table,1,tableLen,F);
        fwrite(target,1,targetLen,F);
    }
    fclose(F);
    printf("Ok\n");
}

void List(char* argv[], char *FileName){
    Header H;
    if (strcmp(argv[3],"--list")!=0) return;
    if (!file_exists(FileName)){
        printf("No file %s\n",FileName);
        return;
    }
    printf("List of %s\n",FileName);
    FILE * F = fopen(FileName,"rb");
    int Pos = 0;
    while (true){
        fseek(F,Pos,SEEK_SET);
        fread(&H,sizeof(H),1,F);
        if (feof(F)) break;
        printf("%s\n",H.filename);
        Pos += sizeof(H)+H.tablesize+H.datasize;
    }
    fclose(F);
}

void TryToExtract(char* argv[], char* FileName){
    Header H;
    if (strcmp(argv[3],"--extract")!=0) return;
    if (!file_exists(FileName)){
        printf("No file %s\n",FileName);
        return;
    }
    printf("Extract of %s\n",FileName);
    FILE * F = fopen(FileName,"rb");
    int Pos = 0;
    while (true){
        fseek(F,Pos,SEEK_SET);
        fread(&H,sizeof(H),1,F);
        if (feof(F)) break;
        Pos += sizeof(H)+H.tablesize+H.datasize;
        printf("extracting %s\n",H.filename);
        target = malloc(H.datasize);
        targetLen = H.datasize;
        if (H.tablesize){
            tableLen = H.tablesize;
            table = malloc(tableLen);
            fread(table,1,tableLen,F);
            fread(target,1,targetLen,F);
            Unpack();
        }
        else{
            fread(target,1,targetLen,F);
            extract();
        }
        FILE * G = fopen(H.filename,"wb+");
        fwrite(source,1,sourceLen,G);
        fclose(G);
    }
    fclose(F);
    printf("Ok\n");
}

int main(int argc, char * argv[]) {
    if (!CheckParameters(argc, argv)){
        printf("usage:\n./run --file FILENAME --{create|extract|list} [file list]\n");
        printf("For Examples:\n");
        printf("./run --file arc.arc --create \n");
        printf("./run --file arc.arc --list\n");
        printf("./run --file arc.arc --extract\n");
        getchar();
        return 1;
    }
    Create(argc,argv, argv[2]);
    List(argv, argv[2]);
    TryToExtract(argv, argv[2]);
    return 0;
}
