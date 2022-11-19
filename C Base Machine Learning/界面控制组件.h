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

//���ɰ�ť���ֱ����밴ť���Ͻǵ����꣬�����ʹ��水ť�����ֵ��ַ����顣
void button(int x, int y, int w, int h, char text[]) {
    //���ɰ�ť����
    setlinecolor(BLACK);
    setfillcolor(RGB(124, 124, 124));
    fillroundrect(x, y, x + w, y + h, 10, 10);

    //������ʾ��ť����
    settextstyle(25, 0, "����");
    setbkmode(TRANSPARENT);
    double width = textwidth(text) / 2.0;
    double heigh = textheight(text) / 2.0;
    outtextxy(x + 0.5 * w - width, y + 0.5 * h - heigh, text);
}
void button1(int x, int y, int w, int h, char text[]) {
    //���ɰ�ť����
    setlinecolor(BLACK);
    setfillcolor(RGB(224, 424, 300));
    fillroundrect(x, y, x + w, y + h, 10, 10);

    //������ʾ��ť����
    settextstyle(25, 0, "����");
    setbkmode(TRANSPARENT);
    double width = textwidth(text) / 2.0;
    double heigh = textheight(text) / 2.0;
    outtextxy(x + 0.5 * w - width, y + 0.5 * h - heigh, text);
}
void button_SGD_ON(int x, int y, int w, int h, char text[]) {
    //���ɰ�ť����
    setlinecolor(BLACK);
    setfillcolor(RED);
    fillroundrect(x, y, x + w, y + h, 10, 10);

    //������ʾ��ť����
    settextstyle(25, 0, "����");
    setbkmode(TRANSPARENT);
    double width = textwidth(text) / 2.0;
    double heigh = textheight(text) / 2.0;
    outtextxy(x + 0.5 * w - width, y + 0.5 * h - heigh, text);
}
void button_SGD_OFF(int x, int y, int w, int h) {
    //���ɰ�ť����
    setlinecolor(WHITE);
    setfillcolor(WHITE);
    fillroundrect(x, y, x + w, y + h, 10, 10);
}

//����ı��򣨲��������˸��
void Text_show(int x, int y, int w, int h, char text[], char name[]) {

    //�����ı��򱳾�
    setlinecolor(BLACK);
    setfillcolor(RGB(250, 250, 250));
    fillrectangle(x, y, x + w, y + h);

    settextcolor(BLACK);
    {
        //������ʾ�ı�
        settextstyle(20, 0, "����");
        setbkmode(TRANSPARENT);
        double width = textwidth(text);
        double heigh = textheight(text) / 2.0;
        outtextxy(x + 3, y + 0.5 * h - heigh, text);
    }


    //������ʾ�ı�������
    settextstyle(20, 0, "����");
    setbkmode(TRANSPARENT);
    double width = textwidth(name);
    double heigh = textheight(name) / 2.0;
    outtextxy(x - width - 10, y + 0.5 * h - heigh, name);
}
//��Ϣ��ʾ
void Inform_show(int x, int y, int w, int h, char text[], char name[]) {

    //�����ı��򱳾�
    setlinecolor(BLACK);
    setfillcolor(RGB(400, 440, 480));
    fillrectangle(x, y, x + w, y + h);

    settextcolor(BLACK);
    {
        //������ʾ�ı�
        settextstyle(15, 0, "����");
        setbkmode(TRANSPARENT);
        double width = textwidth(text);
        double heigh = textheight(text) / 2.0;
        outtextxy(x + 3, y + 0.5 * h - heigh, text);
    }


    //������ʾ�ı�������
    settextstyle(15, 0, "����");
    setbkmode(TRANSPARENT);
    double width = textwidth(name);
    double heigh = textheight(name) / 2.0;
    outtextxy(x - width - 10, y + 0.5 * h - heigh, name);
}
//������Ϣɾ��
void Inform_delete(int x, int y, int w, int h, char name[]) {

    //�����ı��򱳾�
    setlinecolor(WHITE);
    setfillcolor(WHITE);
    settextstyle(15, 0, "����");
    double width = textwidth(name);

    fillrectangle(x-width-10, y, x + w, y + h);

}

//��Int������ת��Ϊ�ַ���
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
        *ptext = (char*)malloc(sizeof(char) * 2);
        (*ptext)[0] = '0';
        (*ptext)[1] = '\0';
    }
    
}
//��Double������ת��Ϊ�ַ���

void double_to_string (double d,char**ptext, int decimal)
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
    *ptext = (char*)malloc(sizeof(char)*(strlen(dd)+1));
    strcpy(*ptext, dd);

}

//��������
void �����(int x, int y, int w, int h, char text[]) {

    char ���[] = "|";

    double width = textwidth(text);
    double heigh = textheight(text) / 2.0;
    settextstyle(20, 0, "����");
    setbkmode(TRANSPARENT);

    settextcolor(BLACK);
    outtextxy(x + 4 + width, y + 0.5 * h - 10, ���);

}
void �����(int x, int y, int w, int h, char text[]) {

    char ���[] = "|";

    double width = textwidth(text);
    double heigh = textheight(text) / 2.0;
    settextstyle(20, 0, "����");
    setbkmode(TRANSPARENT);

    settextcolor(WHITE);
    outtextxy(x + 4 + width, y + 0.5 * h - 10, ���);

}
void С������(int x, int y, int w, int h, char text[]) {

    char С����[] = ".";

    double width = textwidth(text);
    double heigh = textheight(text) / 2.0;
    settextstyle(20, 0, "����");
    setbkmode(TRANSPARENT);

    settextcolor(BLACK);
    outtextxy(x +2 + width, y + 0.5 * h - 10, С����);

}
void С������(int x, int y, int w, int h, char text[]) {

    char С����[] = ".";

    double width = textwidth(text);
    double heigh = textheight(text) / 2.0;
    settextstyle(20, 0, "����");
    setbkmode(TRANSPARENT);

    settextcolor(WHITE);
    outtextxy(x+2 + width, y + 0.5 * h - 10, С����);

}

//�ı���Ķ�ȡ״̬���ں��˹����˸
void Text_Box_for_int(int x, int y, int w, int h, char name[], int* num) {
    ExMessage msg;
    int is_True = 1;

    while (is_True)
    {
        {
            char* Text;
            IntToString(*num, &Text);
            �����(x, y, w, h, Text);
        }


        for (int i = 0; i < 100000; i++) {
            if (peekmessage(&msg, EM_MOUSE)) {
                switch (msg.message)
                {
                case WM_LBUTTONDOWN:
                    if (msg.x <= x || msg.x >= x + w || msg.y <= y || msg.y >= y + h) {
                        char* Text;
                        IntToString(*num, &Text);
                        �����(x, y, w, h, Text);
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
            �����(x, y, w, h, Text);
        }

        for (int i = 0; i < 100000; i++) {
            if (peekmessage(&msg, EM_MOUSE)) {
                switch (msg.message)
                {
                case WM_LBUTTONDOWN:
                    if (msg.x <= x || msg.x >= x + w || msg.y <= y || msg.y >= y + h) {
                        char* Text;
                        IntToString(*num, &Text);
                        �����(x, y, w, h, Text);
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
            �����(x, y, w, h, Text);
        }


        for (int i = 0; i < 100000; i++) {
            if (peekmessage(&msg, EM_MOUSE)) {
                switch (msg.message)
                {
                case WM_LBUTTONDOWN:
                    if (msg.x <= x || msg.x >= x + w || msg.y <= y || msg.y >= y + h) {
                        char* Text;
                        double_to_string(*num / pow(10, Decimal_places), &Text, Decimal_places);
                        �����(x, y, w, h, Text);
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
                    С������(x, y, w, h, Text);
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
                С������(x, y, w, h, Text);
                only_has_point = 1;
                Sleep(200);
            }

            for (int i = 48; i < 58; i++) {
                if (GetAsyncKeyState(i) & 0x8000 && *num < 10000000) {

                    {
                        char* Text;
                        double_to_string(*num / pow(10, Decimal_places), &Text, Decimal_places);
                        С������(x, y, w, h, Text);
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
            �����(x, y, w, h, Text);
        }

        for (int i = 0; i < 100000; i++) {
            if (peekmessage(&msg, EM_MOUSE)) {
                switch (msg.message)
                {
                case WM_LBUTTONDOWN:
                    if (msg.x <= x || msg.x >= x + w || msg.y <= y || msg.y >= y + h) {
                        char* Text;
                        double_to_string(*num / pow(10, Decimal_places), &Text, Decimal_places);
                        �����(x, y, w, h, Text);
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
                    С������(x, y, w, h, Text);
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
                С������(x, y, w, h, Text);
                only_has_point = 1;
                Sleep(200);
            }

            for (int i = 48; i < 58; i++) {
                if (GetAsyncKeyState(i) & 0x8000 && *num < 10000000) {

                    {
                        char* Text;
                        double_to_string(*num / pow(10, Decimal_places), &Text, Decimal_places);
                        С������(x, y, w, h, Text);
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
