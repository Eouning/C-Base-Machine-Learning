#include "framework.h"
#include "C Base Machine Learning.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <graphics.h>
#include <easyx.h>
#include <string.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include <io.h>
#include <direct.h>

void BGM();
void Error();

//生成按钮。分别输入按钮左上角的坐标，长宽，和储存按钮上文字的字符数组。
//以下为四种类型的按钮，分别用于不同场合
void button(int x, int y, int w, int h, char text[]) {
    //生成按钮背景
    setlinecolor(BLACK);
    setfillcolor(RGB(124, 124, 124));
    fillroundrect(x, y, x + w, y + h, 10, 10);

    //居中显示按钮文字
    settextstyle(25, 0, "黑体");
    setbkmode(TRANSPARENT);
    double width = textwidth(text) / 2.0;
    double heigh = textheight(text) / 2.0;
    outtextxy(x + 0.5 * w - width, y + 0.5 * h - heigh, text);
}
void button1(int x, int y, int w, int h, char text[]) {
    //生成按钮背景
    setlinecolor(BLACK);
    setfillcolor(RGB(224, 424, 300));
    fillroundrect(x, y, x + w, y + h, 10, 10);

    //居中显示按钮文字
    settextstyle(25, 0, "黑体");
    setbkmode(TRANSPARENT);
    double width = textwidth(text) / 2.0;
    double heigh = textheight(text) / 2.0;
    outtextxy(x + 0.5 * w - width, y + 0.5 * h - heigh, text);
}
void button_SGD_ON(int x, int y, int w, int h, char text[]) {
    //生成按钮背景
    setlinecolor(BLACK);
    setfillcolor(RED);
    fillroundrect(x, y, x + w, y + h, 10, 10);

    //居中显示按钮文字
    settextstyle(25, 0, "黑体");
    setbkmode(TRANSPARENT);
    double width = textwidth(text) / 2.0;
    double heigh = textheight(text) / 2.0;
    outtextxy(x + 0.5 * w - width, y + 0.5 * h - heigh, text);
}
void button_SGD_OFF(int x, int y, int w, int h) {
    //生成按钮背景
    setlinecolor(WHITE);
    setfillcolor(WHITE);
    fillroundrect(x, y, x + w, y + h, 10, 10);
}

//输出文本框（不含光标闪烁）
void Text_show(int x, int y, int w, int h, char text[], char name[]) {

    //生成文本框背景
    setlinecolor(BLACK);
    setfillcolor(RGB(250, 250, 250));
    fillrectangle(x, y, x + w, y + h);

    settextcolor(BLACK);
    {
        //靠左显示文本
        settextstyle(20, 0, "黑体");
        setbkmode(TRANSPARENT);
        double width = textwidth(text);
        double heigh = textheight(text) / 2.0;
        outtextxy(x + 3, y + 0.5 * h - heigh, text);
    }


    //在左显示文本框名称
    settextstyle(20, 0, "黑体");
    setbkmode(TRANSPARENT);
    double width = textwidth(name);
    double heigh = textheight(name) / 2.0;
    outtextxy(x - width - 10, y + 0.5 * h - heigh, name);
}
//信息显示
void Inform_show(int x, int y, int w, int h, char text[], char name[]) {

    //生成文本框背景
    setlinecolor(BLACK);
    setfillcolor(RGB(400, 440, 480));
    fillrectangle(x, y, x + w, y + h);

    settextcolor(BLACK);
    {
        //靠左显示文本
        settextstyle(15, 0, "黑体");
        setbkmode(TRANSPARENT);
        double width = textwidth(text);
        double heigh = textheight(text) / 2.0;
        outtextxy(x + 3, y + 0.5 * h - heigh, text);
    }


    //在左显示文本框名称
    settextstyle(15, 0, "黑体");
    setbkmode(TRANSPARENT);
    double width = textwidth(name);
    double heigh = textheight(name) / 2.0;
    outtextxy(x - width - 10, y + 0.5 * h - heigh, name);
}
//过程信息删除
void Inform_delete(int x, int y, int w, int h, char name[]) {

    //生成文本框背景
    setlinecolor(WHITE);
    setfillcolor(WHITE);
    settextstyle(15, 0, "黑体");
    double width = textwidth(name);

    fillrectangle(x-width-10, y, x + w, y + h);

}

//将Int型数据转化为字符串
void IntToString(int x, char** ptext) {
    char Text[30];
    int Num = 0;

    if (x != 0) {
        while (x > 0) {
            Text[Num] = (x % 10) + 48;
            x /= 10;
            Num++;
        }
        *ptext = (char*)malloc(sizeof(char) * Num);
        for (int i = Num - 1; i >= 0; i--) {
            (*ptext)[Num - i - 1] = Text[i];
        }
        (*ptext)[Num] = '\0';
    }
    else
    {
        char* p = (char*)malloc(sizeof(char) * 2);
        if (p == NULL) {
            exit(0);
        }
        *ptext = p;
        (*ptext)[0] = '0';
        (*ptext)[1] = '\0';
    }
    
}
//将Double型数据转化为字符串

int double_to_string (double d,char**ptext, int decimal)
{
    if (d < 1000000 && fabs(d - 1000000)>1e-6 && d > -1000000 && fabs(d + 1000000)>1e-6)
    {
        decimal = decimal < 0 ? 0 : decimal;
        char dd[20];
        switch (decimal) {
        case 0:
            sprintf(dd, "%.0lf", d);
            break;
        case 1:
            sprintf(dd, "%.1lf", d);
            break;
        case 2:
            sprintf(dd, "%.2lf", d);
            break;
        case 3:
            sprintf(dd, "%.3lf", d);
            break;
        case 4:
            sprintf(dd, "%.4lf", d);
            break;
        case 5:
            sprintf(dd, "%.5lf", d);
            break;
        default:
            sprintf(dd, "%.6lf", d);
            break;

        }
        char* p = (char*)malloc(sizeof(char) * (strlen(dd)+30));
        if (p == NULL) {
            exit(0);
        }
        *ptext = p;
        strcpy(*ptext, dd);

        return 0;
    }
    else if (d >=1000000 || d<=-1000000)
    {
        Error();
        return 1;
    }
    else
    {
        char* p = (char*)malloc(sizeof(char)*10);
        if (p == NULL) {
            exit(0);
        }
        *ptext = p;
        strcpy(*ptext, "无穷大");

        return 0;
    }
}

//见函数名
void 光标闪(int x, int y, int w, int h, char text[]) {

    char 光标[] = "|";

    double width = textwidth(text);
    double heigh = textheight(text) / 2.0;
    settextstyle(20, 0, "黑体");
    setbkmode(TRANSPARENT);

    settextcolor(BLACK);
    outtextxy(x + 4 + width, y + 0.5 * h - 10, 光标);

}
void 光标灭(int x, int y, int w, int h, char text[]) {

    char 光标[] = "|";

    double width = textwidth(text);
    double heigh = textheight(text) / 2.0;
    settextstyle(20, 0, "黑体");
    setbkmode(TRANSPARENT);

    settextcolor(WHITE);
    outtextxy(x + 4 + width, y + 0.5 * h - 10, 光标);

}
void 小数点有(int x, int y, int w, int h, char text[]) {

    char 小数点[] = ".";

    double width = textwidth(text);
    double heigh = textheight(text) / 2.0;
    settextstyle(20, 0, "黑体");
    setbkmode(TRANSPARENT);

    settextcolor(BLACK);
    outtextxy(x +2 + width, y + 0.5 * h - 10, 小数点);

}
void 小数点无(int x, int y, int w, int h, char text[]) {

    char 小数点[] = ".";

    double width = textwidth(text);
    double heigh = textheight(text) / 2.0;
    settextstyle(20, 0, "黑体");
    setbkmode(TRANSPARENT);

    settextcolor(WHITE);
    outtextxy(x+2 + width, y + 0.5 * h - 10, 小数点);

}

//文本框的读取状态，融合了光标闪烁
void Text_Box_for_int(int x, int y, int w, int h, char name[], int* num) {
    ExMessage msg;
    int is_True = 1;

    while (is_True)
    {
        {
            char* Text;
            IntToString(*num, &Text);
            光标闪(x, y, w, h, Text);
        }


        for (int i = 0; i < 100000; i++) {
            if (peekmessage(&msg, EM_MOUSE)) {
                switch (msg.message)
                {
                case WM_LBUTTONDOWN:
                    if (msg.x <= x || msg.x >= x + w || msg.y <= y || msg.y >= y + h) {
                        char* Text;
                        IntToString(*num, &Text);
                        光标灭(x, y, w, h, Text);
                        is_True = 0;
                    }
                    break;
                default:
                    break;
                }
            }

            if (GetAsyncKeyState(VK_BACK) & 0x8000) {
                *num /= 10;
                char* Text;
                IntToString(*num, &Text);
                Text_show(x, y, w, h, Text, name);
                Sleep(200);
            }

            for (int i = 48; i < 58; i++) {
                if (GetAsyncKeyState(i) & 0x8000 && *num < 100000000) {
                    *num = (*num) * 10 + i - 48;
                    char* Text;
                    IntToString(*num, &Text);
                    Text_show(x, y, w, h, Text, name);
                    Sleep(200);
                }
            }

        }

        {
            char* Text;
            IntToString(*num, &Text);
            光标灭(x, y, w, h, Text);
        }

        for (int i = 0; i < 100000; i++) {
            if (peekmessage(&msg, EM_MOUSE)) {
                switch (msg.message)
                {
                case WM_LBUTTONDOWN:
                    if (msg.x <= x || msg.x >= x + w || msg.y <= y || msg.y >= y + h) {
                        char* Text;
                        IntToString(*num, &Text);
                        光标灭(x, y, w, h, Text);
                        is_True = 0;
                    }
                    break;
                default:
                    break;
                }
            }

            if (GetAsyncKeyState(VK_BACK) & 0x8000) {
                *num /= 10;
                char* Text;
                IntToString(*num, &Text);
                Text_show(x, y, w, h, Text, name);
                Sleep(200);
            }

            for (int i = 48; i < 58; i++) {
                if (GetAsyncKeyState(i) & 0x8000 & 0x8000 && *num < 100000000) {
                    *num = (*num) * 10 + i - 48;
                    char* Text;
                    IntToString(*num, &Text);
                    Text_show(x, y, w, h, Text, name);
                    Sleep(200);
                }
            }

        }
    }
}

void Text_Box_for_double(int x, int y, int w, int h, char name[], double* num) {
    ExMessage msg;
    int only_has_point = 0;
    int is_True = 1;

    int Decimal_places = 0;
    while (*num-(int)*num>0)
    {
        (*num) *= 10;
        Decimal_places++;
    }

    while (is_True)
    {
        {
            char* Text;
            double_to_string(*num / pow(10, Decimal_places), &Text, Decimal_places);
            光标闪(x, y, w, h, Text);
        }


        for (int i = 0; i < 100000; i++) {
            if (peekmessage(&msg, EM_MOUSE)) {
                switch (msg.message)
                {
                case WM_LBUTTONDOWN:
                    if (msg.x <= x || msg.x >= x + w || msg.y <= y || msg.y >= y + h) {
                        char* Text;
                        double_to_string(*num / pow(10, Decimal_places), &Text, Decimal_places);
                        光标灭(x, y, w, h, Text);
                        *num /= pow(10, Decimal_places);
                        is_True = 0;
                    }
                    break;
                default:
                    break;
                }
            }

            if (GetAsyncKeyState(VK_BACK) & 0x8000) {
                {
                    char* Text;
                    double_to_string(*num / pow(10, Decimal_places), &Text, Decimal_places);
                    小数点无(x, y, w, h, Text);
                }

                *num /= 10;
                *num = (int)*num;
                if (Decimal_places>0) {
                    Decimal_places--;
                }

                char* Text;
                double_to_string(*num / pow(10, Decimal_places), &Text, Decimal_places);
                Text_show(x, y, w, h, Text, name);
                Sleep(200);
            }

            if (GetAsyncKeyState(VK_OEM_PERIOD) & 0x8000 && Decimal_places==0) {
                char* Text;
                double_to_string(*num / pow(10, Decimal_places), &Text, Decimal_places);
                小数点有(x, y, w, h, Text);
                only_has_point = 1;
                Sleep(200);
            }

            for (int i = 48; i < 58; i++) {
                if (GetAsyncKeyState(i) & 0x8000 && *num < 10000000) {

                    {
                        char* Text;
                        double_to_string(*num / pow(10, Decimal_places), &Text, Decimal_places);
                        小数点无(x, y, w, h, Text);
                    }

                    if (Decimal_places > 0 || only_has_point)
                    {
                        only_has_point = 0;
                        Decimal_places++;
                    }
                    *num = (*num) * 10 + i - 48;
                    char* Text;
                    double_to_string(*num / pow(10, Decimal_places), &Text, Decimal_places);
                    Text_show(x, y, w, h, Text, name);
                    Sleep(200);
                }
            }

        }

        {
            char* Text;
            double_to_string(*num / pow(10, Decimal_places), &Text, Decimal_places);
            光标灭(x, y, w, h, Text);
        }

        for (int i = 0; i < 100000; i++) {
            if (peekmessage(&msg, EM_MOUSE)) {
                switch (msg.message)
                {
                case WM_LBUTTONDOWN:
                    if (msg.x <= x || msg.x >= x + w || msg.y <= y || msg.y >= y + h) {
                        char* Text;
                        double_to_string(*num / pow(10, Decimal_places), &Text, Decimal_places);
                        光标灭(x, y, w, h, Text);
                        *num /= pow(10, Decimal_places);
                        is_True = 0;
                    }
                    break;
                default:
                    break;
                }
            }

            if (GetAsyncKeyState(VK_BACK) & 0x8000) {
                {
                    char* Text;
                    double_to_string(*num / pow(10, Decimal_places), &Text, Decimal_places);
                    小数点无(x, y, w, h, Text);
                }

                *num /= 10;
                *num = (int)*num;
                if (Decimal_places > 0) {
                    Decimal_places--;
                }

                char* Text;
                double_to_string(*num / pow(10, Decimal_places), &Text, Decimal_places);
                Text_show(x, y, w, h, Text, name);
                Sleep(200);
            }

            if (GetAsyncKeyState(VK_OEM_PERIOD) & 0x8000 && Decimal_places == 0) {
                char* Text;
                double_to_string(*num / pow(10, Decimal_places), &Text, Decimal_places);
                小数点有(x, y, w, h, Text);
                only_has_point = 1;
                Sleep(200);
            }

            for (int i = 48; i < 58; i++) {
                if (GetAsyncKeyState(i) & 0x8000 && *num < 10000000) {

                    {
                        char* Text;
                        double_to_string(*num / pow(10, Decimal_places), &Text, Decimal_places);
                        小数点无(x, y, w, h, Text);
                    }

                    if (Decimal_places > 0 || only_has_point)
                    {
                        only_has_point = 0;
                        Decimal_places++;
                    }
                    *num = (*num) * 10 + i - 48;
                    char* Text;
                    double_to_string(*num / pow(10, Decimal_places), &Text, Decimal_places);
                    Text_show(x, y, w, h, Text, name);
                    Sleep(200);
                }
            }

        }
    }
}

//按钮按下音效
void BGM() {
    mciSendString("close 01", NULL, 0, NULL);

    //打开音乐，播放音乐
    mciSendString("open ./button.wav alias 01", 0, 0, 0);
    mciSendString("play 01", 0, 0, 0);
}
//背景音乐
void BGM2() {
    mciSendString("close 02", NULL, 0, NULL);
    //打开音乐，播放音乐
    mciSendString("open ./Back.mp3 alias 02 type MPEGVideo", 0, 0, 0);
    mciSendString("play 02 repeat", 0, 0, 0);
}
//错误溢出的弹窗
void Error() {
    closegraph();
    
    //错误提示窗口
    initgraph(400,300);//背景分辨率
    setbkcolor(WHITE);//背景颜色

    cleardevice();//清空

    char text1[] = "出错了！";
    char text2[] = "可能是学习率太大导致的参数越界。";
    char text3[] = "请按下下方按钮初始化后重试！";
    settextcolor(BLACK);
    settextstyle(15, 0, "黑体");
    setbkmode(TRANSPARENT);
    outtextxy(150, 50, text1);
    outtextxy(70, 90, text2);
    outtextxy(85, 130, text3);

    char buttonText[] = "初始化程序";
    button(120, 200, 150, 50, buttonText);

    while (true)
    {
        ExMessage msg;
        setlinecolor(BLACK);
        setfillcolor(BLACK);

        if (peekmessage(&msg, EM_MOUSE)) {
            switch (msg.message)
            {
            case WM_LBUTTONDOWN:

                //打点后训练集增长
                if (msg.x >= 120 && msg.x <= 270 && msg.y >=200 && msg.y <= 250) {
                    goto Next;
                }
            default:
                break;
            }
        }
    }

Next:

    closegraph();
}