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
#include <string>
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"Imm32.lib")

void button(int x, int y, int w, int h, char text[]);

//���Իع���ʾ����
void Linear_regression_presentaion() {

    double* p_x=(double*)malloc(sizeof(double)*1000);
    double* p_y = (double*)malloc(sizeof(double) * 1000);
    int NUM = 0;

    initgraph(1024, 768);//�����ֱ���
    setbkcolor(WHITE);//������ɫ

Ori:

    NUM = 0;
    cleardevice();//���

    HWND hWnd = GetHWnd();
    SetWindowText(hWnd, "��ֻ��һ����ͨ�Ĵ������� O-O");

    setlinecolor(BLACK);
    setfillcolor(BLACK);
    fillrectangle(0, 0, 1024, 5);
    fillrectangle(0, 0, 5, 768);
    fillrectangle(0, 763, 1024,768);
    fillrectangle(1019, 0, 1024, 768);

    setlinecolor(RGB(124,124,124));
    setfillcolor(RGB(234, 234, 234));
    fillrectangle(25, 25, 725, 600);

    char buttonText1[] = "��ʼ���Իع�";
    button(50, 650, 200, 50, buttonText1);

    char buttonText2[] = "��ʼ��";
    button(430, 650, 200, 50, buttonText2);

    char buttonText3[] = "��������";
    button(780, 650, 200, 50, buttonText3);

    while (true)
    {

        ExMessage msg;
        setlinecolor(BLACK);
        setfillcolor(BLACK);

        if (peekmessage(&msg, EM_MOUSE)) {
            switch (msg.message)
            {
            case WM_LBUTTONDOWN:
                //��������˿�ʼ��Ϸ��ť
                if (msg.x >= 25 && msg.x <= 725 && msg.y >= 25 && msg.y <= 600) {
                    fillcircle(msg.x, msg.y, 2);
                    p_x[NUM] = msg.x;
                    p_y[NUM] = msg.y;
                    NUM++;
                }
                if (msg.x >= 430 && msg.x <= 630 && msg.y >= 650 && msg.y <= 700) {
                    goto Ori;
                }
                if (msg.x >= 50 && msg.x <= 250 && msg.y >= 650 && msg.y <= 700)
                {
                    goto Next;
                }
                if (msg.x >= 780 && msg.x <= 980 && msg.y >= 650 && msg.y <= 700)
                {
                    exit(0);
                }
                break;
            default:
                break;
            }
        }
    }

Next:
    while (true)
    {

    }


}

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

using namespace std;
void GetIMEString(HWND hWnd, string& str)
{
    HIMC hIMC = ImmGetContext(hWnd);//��ȡHIMC 
    if (hIMC)
    {
        //������˵��һ�£������롰�й���Ϊ�� 
        //�л����������뷨�����롰zhongguo��������ַ�������IME����ַ��� 
        //�������뷨�б���ѡ����ַ������й��������IME����ַ��� 
        static bool flag = false;//������ɱ�ǣ���������ʱ��IME����ַ�����Ϊ�գ���true��������ɺ�IME����ַ���Ϊ�գ���false 
        DWORD dwSize = ImmGetCompositionStringW(hIMC, GCS_COMPSTR, NULL, 0); //��ȡIME���������ַ����ĳ��� 
        if (dwSize > 0)//���IME����ַ�����Ϊ�գ���û�д��󣨴�ʱdwSizeΪ��ֵ��������������ɱ��Ϊtrue 
        {
            if (flag == false)
            {
                flag = true;
            }
        }
        else if (dwSize == 0 && flag) //���IME����ַ���Ϊ�գ����ұ��Ϊtrue�����ȡIME����ַ��� 
        {
            int iSize; //IME����ַ����Ĵ�С 
            LPSTR pszMultiByte = NULL;//IME����ַ���ָ�� 
            int ChineseSimpleAcp = 936;//���ֽ�ת��ʱ���ĵı��� 
            WCHAR* lpWideStr = NULL;//���ֽ��ַ����� 
            dwSize = ImmGetCompositionStringW(hIMC, GCS_RESULTSTR, NULL, 0);//��ȡIME����ַ����Ĵ�С 
            if (dwSize > 0) //���IME����ַ�����Ϊ�գ���û�д��� 
            {
                dwSize += sizeof(WCHAR);//��СҪ����NULL������ 
                //Ϊ��ȡIME����ַ�������ռ� 
                if (lpWideStr)
                {
                    delete[]lpWideStr;
                    lpWideStr = NULL;
                }
                lpWideStr = new WCHAR[dwSize];
                memset(lpWideStr, 0, dwSize); //��ս���ռ� 
                ImmGetCompositionStringW(hIMC, GCS_RESULTSTR, lpWideStr, dwSize);//��ȡIME����ַ����������ȡ���ǿ��ֽ� 
                iSize = WideCharToMultiByte(ChineseSimpleAcp, 0, lpWideStr, -1, NULL, 0, NULL, NULL);//���㽫IME����ַ���ת��ΪASCII��׼�ֽں�Ĵ�С 
                //Ϊת������ռ� 
                if (pszMultiByte)
                {
                    delete[] pszMultiByte;
                    pszMultiByte = NULL;
                }
                pszMultiByte = new char[iSize + 1];
                WideCharToMultiByte(ChineseSimpleAcp, 0, lpWideStr, -1, pszMultiByte, iSize, NULL, NULL);//���ֽ�ת�� 
                pszMultiByte[iSize] = '\0';
                str += pszMultiByte;//��ӵ�string�� 
                //�ͷſռ� 
                if (lpWideStr)
                {
                    delete[]lpWideStr;
                    lpWideStr = NULL;
                }
                if (pszMultiByte)
                {
                    delete[] pszMultiByte;
                    pszMultiByte = NULL;
                }
            }
            flag = false;
        }
        ImmReleaseContext(hWnd, hIMC);//�ͷ�HIMC 
    }
}