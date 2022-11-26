#include "线性回归相关.h"
#define Wide 350
#define Height 300

//文件结果输出
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

    char* p = (char*)malloc(sizeof(char) * ((Rank + 1) * 16 + 27));
    if (p==NULL)
    {
        exit(0);
    }
    char* FileContent = p;
    strcat(FileContent, "本次线性回归的结果为：");
    int Count = Rank;
    while (Count>0)
    {
        char* pt;
        double_to_string(w[Rank - Count], &pt, 5);
        if (strcmp(pt, "无穷大") == 0) {
            goto Error;
        }
        strcat(FileContent, pt);
        free(pt);

        if (Count == 1) {
            strcat(FileContent, "X+");
        }
        else
        {
            strcat(FileContent,"X^");
            char* pt;
            IntToString(Count, &pt);
            strcat(FileContent, pt);
            free(pt);
            strcat(FileContent, "+");
        }
        Count--;
    }
    char* pt;
    double_to_string(b, &pt, 5);
    if (strcmp(pt, "无穷大") == 0) {
        goto Error;
    }
    strcat(FileContent, pt);
    free(pt);
    fprintf(fp, FileContent);

    fclose(fp);
    free(FileContent);
    free(FilePosition);

    goto Over;
Error:
    strcpy(FileContent, "本函数拟合失败，请调整学习率后重试");
    fprintf(fp, FileContent);

    fclose(fp);
    free(FileContent);
    free(FilePosition);
Over:
    int 占位用的 = 0;
}
