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

//线性回归演示界面
void Linear_regression_presentaion() {

    double* p_x=(double*)malloc(sizeof(double)*1000);
    double* p_y = (double*)malloc(sizeof(double) * 1000);
    int NUM = 0;

    initgraph(1024, 768);//背景分辨率
    setbkcolor(WHITE);//背景颜色

Ori:

    NUM = 0;
    cleardevice();//清空

    HWND hWnd = GetHWnd();
    SetWindowText(hWnd, "这只是一个普通的窗口名称 O-O");

    setlinecolor(BLACK);
    setfillcolor(BLACK);
    fillrectangle(0, 0, 1024, 5);
    fillrectangle(0, 0, 5, 768);
    fillrectangle(0, 763, 1024,768);
    fillrectangle(1019, 0, 1024, 768);

    setlinecolor(RGB(124,124,124));
    setfillcolor(RGB(234, 234, 234));
    fillrectangle(25, 25, 725, 600);

    char buttonText1[] = "开始线性回归";
    button(50, 650, 200, 50, buttonText1);

    char buttonText2[] = "初始化";
    button(430, 650, 200, 50, buttonText2);

    char buttonText3[] = "结束进程";
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
                //如果按下了开始游戏按钮
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

//生成按钮。分别输入按钮左上角的坐标，长宽，和储存按钮上文字的字符数组。
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

using namespace std;
void GetIMEString(HWND hWnd, string& str)
{
    HIMC hIMC = ImmGetContext(hWnd);//获取HIMC 
    if (hIMC)
    {
        //这里先说明一下，以输入“中国”为例 
        //切换到中文输入法后，输入“zhongguo”，这个字符串称作IME组成字符串 
        //而在输入法列表中选择的字符串“中国”则称作IME结果字符串 
        static bool flag = false;//输入完成标记：在输入中时，IME组成字符串不为空，置true；输入完成后，IME组成字符串为空，置false 
        DWORD dwSize = ImmGetCompositionStringW(hIMC, GCS_COMPSTR, NULL, 0); //获取IME组成输入的字符串的长度 
        if (dwSize > 0)//如果IME组成字符串不为空，且没有错误（此时dwSize为负值），则置输入完成标记为true 
        {
            if (flag == false)
            {
                flag = true;
            }
        }
        else if (dwSize == 0 && flag) //如果IME组成字符串为空，并且标记为true，则获取IME结果字符串 
        {
            int iSize; //IME结果字符串的大小 
            LPSTR pszMultiByte = NULL;//IME结果字符串指针 
            int ChineseSimpleAcp = 936;//宽字节转换时中文的编码 
            WCHAR* lpWideStr = NULL;//宽字节字符数组 
            dwSize = ImmGetCompositionStringW(hIMC, GCS_RESULTSTR, NULL, 0);//获取IME结果字符串的大小 
            if (dwSize > 0) //如果IME结果字符串不为空，且没有错误 
            {
                dwSize += sizeof(WCHAR);//大小要加上NULL结束符 
                //为获取IME结果字符串分配空间 
                if (lpWideStr)
                {
                    delete[]lpWideStr;
                    lpWideStr = NULL;
                }
                lpWideStr = new WCHAR[dwSize];
                memset(lpWideStr, 0, dwSize); //清空结果空间 
                ImmGetCompositionStringW(hIMC, GCS_RESULTSTR, lpWideStr, dwSize);//获取IME结果字符串，这里获取的是宽字节 
                iSize = WideCharToMultiByte(ChineseSimpleAcp, 0, lpWideStr, -1, NULL, 0, NULL, NULL);//计算将IME结果字符串转换为ASCII标准字节后的大小 
                //为转换分配空间 
                if (pszMultiByte)
                {
                    delete[] pszMultiByte;
                    pszMultiByte = NULL;
                }
                pszMultiByte = new char[iSize + 1];
                WideCharToMultiByte(ChineseSimpleAcp, 0, lpWideStr, -1, pszMultiByte, iSize, NULL, NULL);//宽字节转换 
                pszMultiByte[iSize] = '\0';
                str += pszMultiByte;//添加到string中 
                //释放空间 
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
        ImmReleaseContext(hWnd, hIMC);//释放HIMC 
    }
}