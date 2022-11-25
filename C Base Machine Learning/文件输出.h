#include "线性回归相关.h"
#define Wide 350
#define Height 300

void FileOutput(double w[], double b, int Rank) {
    int FileCount = 1;
    char folderName[] = "1";
    while (_access(folderName, 0) != -1) {
        FileCount++;
        char* a;
        IntToString(FileCount, &a);
        strcpy(folderName, a);
        free(a);
    }
    _mkdir(folderName);

    char* FilePosition = (char*)malloc(sizeof(char) * 100);
    strcpy(FilePosition, folderName);
    char TxtName[] = "\\本次线性回归函数.txt";
    strcat(FilePosition, TxtName);
    FILE* fp = fopen(FilePosition, "a");
    switch (Rank)
    {
    case 1:
        fprintf(fp, "本次回归函数为：%lfX+%lf", w[0], b);
        break;
    case 2:
        fprintf(fp, "本次回归函数为：%lfX^2+%lfX+%lf",w[0],w[1], b);
        break;
    case 3:
        fprintf(fp, "本次回归函数为：%lfX^3+%lfX^2+%lfX+%lf", w[0], w[1],w[2],b);
        break;
    case 4:
        fprintf(fp, "本次回归函数为：%lfX^4+%lfX^3+%lfX^2+%lfX+%lf", w[0], w[1], w[2],w[3], b);
        break;
    case 5:
        fprintf(fp, "本次回归函数为：%lfX^5+%lfX^4+%lfX^3+%lfX^2+%lfX+%lf", w[0], w[1], w[2], w[3], w[4],b);
        break;
    case 6:
        fprintf(fp, "本次回归函数为：%lfX^6+%lfX^5+%lfX^4+%lfX^3+%lfX^2+%lfX+%lf", w[0], w[1], w[2], w[3], w[4],w[5], b);
        break;
    case 7:
        fprintf(fp, "本次回归函数为：%lfX^7+%lfX^6+%lfX^5+%lfX^4+%lfX^3+%lfX^2+%lfX+%lf", w[0], w[1], w[2], w[3], w[4], w[5], w[6],b);
        break;
    default:
        break;
    }
    fclose(fp);

    free(FilePosition);
}

