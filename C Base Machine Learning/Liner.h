#include "线性回归相关.h"

//线性回归演示界面
void Linear_regression_presentaion() {

    //创建画布
    initgraph(1024, 768);//背景分辨率
    setbkcolor(WHITE);//背景颜色

Ori:
    cleardevice();//清空

    //初始化
    char TextName2[] = "拟合阶数:";
    char TextName1[] = "学习次数:";
    char TextName3[] = "学习率:";

    int count = 0;//数据集中数据个数
    int Rank = 1;
    int interation = 100000;
    double Learning_rat =100;
    Train* Head=NULL;

    setlinecolor(BLACK);
    setfillcolor(BLACK);
    fillrectangle(0, 0, 1024, 5);
    fillrectangle(0, 0, 5, 768);
    fillrectangle(0, 763, 1024, 768);
    fillrectangle(1019, 0, 1024, 768);

    setlinecolor(RGB(124, 124, 124));
    setfillcolor(RGB(234, 234, 234));
    fillrectangle(25, 25, 725, 600);

    HWND hWnd = GetHWnd();
    SetWindowText(hWnd, "这只是一个普通的窗口名称 O-O");

Again:

    char buttonText1[] = "开始线性回归";
    button(50, 650, 200, 50, buttonText1);

    char buttonText2[] = "初始化";
    button(430, 650, 200, 50, buttonText2);

    char buttonText3[] = "结束进程";
    button(780, 650, 200, 50, buttonText3);

    char* Text1;
    IntToString(interation, &Text1);
    Text_show(860, 100, 100, 30, Text1, TextName1);

    char* Text2;
    IntToString(Rank, &Text2);
    Text_show(860, 200, 100, 30, Text2, TextName2);

    char* Text3;
    double_to_string(Learning_rat, &Text3, 5);
    Text_show(860, 300, 100, 30, Text3, TextName3);
    
    //循环读入用户鼠标键盘的相关操作
    while (true)
    {
        ExMessage msg;
        setlinecolor(BLACK);
        setfillcolor(BLACK);

        if (peekmessage(&msg, EM_MOUSE)) {
            switch (msg.message)
            {
            case WM_LBUTTONDOWN:

                if (msg.x >= 25 && msg.x <= 725 && msg.y >= 25 && msg.y <= 600) {
                    fillcircle(msg.x, msg.y, 2);
                    Train_append(msg.x-325, msg.y-325, &Head);
                    count++;
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
                if (msg.x >= 860 && msg.x <= 960 && msg.y >= 100 && msg.y <= 130)
                {
                    Text_Box_for_int(860, 100, 100, 30, TextName1, &interation);
                }
                if (msg.x >= 860 && msg.x <= 960 && msg.y >= 200 && msg.y <= 230)
                {
                    Text_Box_for_int(860, 200, 100, 30, TextName2, &Rank);
                }
                if (msg.x >= 860 && msg.x <= 960 && msg.y >= 300 && msg.y <= 330)
                {
                    Text_Box_for_double(860,300, 100, 30, TextName3, &Learning_rat);
                }
                break;
            default:
                break;
            }
        }
    }

//正式开始线性回归演示
Next:
    

    //初始化w[]与b
    double* w = (double*)malloc(sizeof(double) * Rank);
    double b = 0;
    for (int i = 0; i < Rank; i++) {
        w[i] = 0;
    }

    //线性回归实现
    Liner(10000*interation, 0.0000001*Learning_rat, Head, w, &b,Rank,count);

    char TextName8[] = "b:";
    char* Text8;
    double_to_string(b, &Text8, 7);
    Text_show(860, 400, 100, 30, Text8, TextName8);

    char TextName9[] = "w[最高位]:";
    char* Text9;
    double_to_string(w[0], &Text9, 7);
    Text_show(860, 450, 100, 30, Text9, TextName9);

    setlinecolor(BLUE);
    double y_o = now(25, w, b, Rank);
    for (double i = 25.1; i < 725; i+=0.1) {
        double y = now(i-325, w, b, Rank)+325;
        if (y>25 && y <600) {
            if (y_o > 25 && y_o < 600) {
                line(i - 0.1, y_o, i, y);
            }
            else
            {
                line(i, y, i, y);
            }
        }
        y_o = y;
    }

    //确保点在线上
    Train* p = Head;
    while (p)
    {
        setlinecolor(BLACK);
        setfillcolor(BLACK);
        fillcircle(p->X + 325, p->Y + 325, 2);
        p = p->Next;
    }

    free(w);

    goto Again;
}
