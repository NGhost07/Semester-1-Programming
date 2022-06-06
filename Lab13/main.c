#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef union A {
    char buffer[12];
    struct AData{
        short int Empty;
        char Ver[3];
        char Ver_1;
        char Ver_2;
        char Flags;
        int Size;
    } DATA;
} TAG;

typedef union B {
    char buffer[10];
    struct BData{
        char Name[4];
        int Size;
        int Flags;
    } frameDATA;
} frameTAG;

int reverse_bit(int size) {
    return ((size >> 24) & 0x000000ff) | ((size >> 8) & 0x0000ff00) | ((size << 8) & 0x00ff0000) | ((size << 24) & 0xff000000);
}

void cop_and_show(FILE *input, FILE *output) {
    int c;
    while ((c = getc(input)) != EOF) {
        putc(c, output);
    }
}

void show_command(char* fileName);
void get_command(char* fileName, char frameName[4]);
void set_command(char* fileName, char frameName[4], char* value);

int main(int argc, char *argv[]) {
    char *fileName = NULL, *frameName = NULL, *value = NULL;
    int show = 0, set = 0, get = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--show") == 0) {
            show = 1;
            continue;
        }
        if (argv[i][2] == 'f') {
            fileName = strpbrk(argv[i], "=") + 1;
        }
        if (argv[i][2] == 'g') {
            get = 1;
            frameName = strpbrk(argv[i], "=") + 1;
            continue;
        }
        if (argv[i][2] == 's') {
            set = 1;
            frameName = strpbrk(argv[i], "=") + 1;
            continue;
        }
        if (argv[i][2] == 'v') {
            value = strpbrk(argv[i], "=") + 1;
            continue;
        }
    }
    if (show == 1) {
        show_command(fileName);
    }
    if (get == 1) {
        get_command(fileName, frameName);
    }
    if (set == 1) {
        set_command(fileName, frameName, value);
    }
}

void show_command(char *fileName) {
    FILE* File = fopen(fileName, "rb");
    fseek(File, 0, 0);
    TAG Tag;
    fread(Tag.buffer + 2, sizeof(char), 10, File);
    int TagSize = reverse_bit(Tag.DATA.Size);
    printf("%s version %d.%d\n", Tag.DATA.Ver, Tag.DATA.Ver_1, Tag.DATA.Ver_2);
    while (ftell(File) < TagSize + 10) {
        frameTAG Frame;
        fread(Frame.buffer, sizeof(char), 10, File);
        if (Frame.frameDATA.Name[0] == 0)
            break;
        printf("%s: ", Frame.frameDATA.Name);
        int FrameSize = reverse_bit(Frame.frameDATA.Size);
        char* FrameContent = malloc(sizeof(char) *FrameSize);
        fread(FrameContent, sizeof(char), FrameSize, File);
        for (int i = 0; i < FrameSize; ++i)
            printf("%c", FrameContent[i]);
        printf("\n");
        free(FrameConten›t);
    }
    fclose(File);
}

void get_command(char *fileName, char frameName[4]) {
    FILE* File = fopen(fileName, "rb");
    TAG Tag;
    fread(Tag.buffer + 2, sizeof(char), 10, File);
    int TagSize = reverse_bit(Tag.DATA.Size);
    while (ftell(File) < TagSize + 10) {
        frameTAG Frame;
        fread(Frame.buffer, sizeof(char), 10, File);
        int FrameSize = reverse_bit(Frame.frameDATA.Size);
        if (strcmp((char*)Frame.frameDATA.Name, frameName) == 0) {
            printf("%s: ", Frame.frameDATA.Name);
            char *FrameContent = malloc(sizeof(char) *FrameSize);
            fread(FrameContent, sizeof(char), FrameSize, File);
            for (int i = 0; i < FrameSize; ++i) {
                printf("%c", FrameContent[i]);
            }
            printf("\n");
            free(FrameContent);
            fclose(File);
            return;
        }
        fseek(File, FrameSize, 1);
    }
    fclose(File);
}

void set_command(char *FileName, char FrameName[4], char *FrameValue) {
    FILE* File = fopen(FileName, "rb");
    TAG Tag;
    fread(Tag.buffer + 2, sizeof(char), 10, File);
    unsigned int TagSize = reverse_bit(Tag.DATA.Size), OldFramePosition = 0,
    OldFrameSize = 0;
    while (ftell(File) < TagSize + 10) {
        frameTAG Frame;
        fread(Frame.buffer, sizeof(char), 10, File);
        unsigned int FrameSize = reverse_bit(Frame.frameDATA.Size);
        if (strcmp(Frame.frameDATA.Name, FrameName) == 0) {
            OldFramePosition = (unsigned int)ftell(File) - 10;
            OldFrameSize = FrameSize;
            break;
        }
        fseek(File, FrameSize, 1);
    }
    unsigned int ValueSize = (unsigned int)strlen(FrameValue), NewTagSize = TagSize - OldFrameSize + ValueSize + 10 * (OldFramePosition != 0);
    if (OldFramePosition == 0) {
        OldFramePosition = (unsigned int)ftell(File);
    }
    if (ValueSize == 0) {
        NewTagSize -= 10;
    }
    FILE* FileCopy = fopen("temp.mp3", "wb");
    fseek(File, 0, 0);
    fseek(FileCopy, 0, 0);
    cop_and_show(File, FileCopy);
    fclose(File);
    fclose(FileCopy);
    FileCopy = fopen("temp.mp3", "rb");
    File = fopen(FileName, "wb");
    Tag.DATA.Size = reverse_bit(NewTagSize);
    fwrite(Tag.buffer + 2, sizeof(char), 10, File);
    fseek(FileCopy, 10, 0);
    for (int i = 0; i < OldFramePosition - 10; ++i) {
        int Char = getc(FileCopy);
        putc(Char, File);
    }
    if (ValueSize > 0) {
        frameTAG Frame;
        for (int i = 0; i < 4; ++i)
            Frame.frameDATA.Name[i] = FrameName[i];
        Frame.frameDATA.Size = reverse_bit(ValueSize);
        Frame.frameDATA.Flags = 0;
        fwrite(Frame.buffer, sizeof(char), 10, File);
    }
    fwrite(FrameValue, sizeof(char), ValueSize, File);
    fseek(FileCopy, OldFramePosition + 10 + OldFrameSize, 0);
    for (int i = (int)ftell(File); i < NewTagSize; ++i) {
        int Char = getc(FileCopy);
        putc(Char, File);
    }
    printf("New %s: %s\n", FrameName, FrameValue);
    cop_and_show(FileCopy, File);
    fclose(File);
    fclose(FileCopy);
    remove("temp.mp3");
}
