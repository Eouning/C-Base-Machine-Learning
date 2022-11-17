#include "界面控制组件.h"

//线性回归演示界面
void Linear_regression_presentaion() {

    //创建画布
    initgraph(1024, 768);//背景分辨率
    setbkcolor(WHITE);//背景颜色

Ori:
    //初始化
    char TextName2[] = "拟合阶数:";
    char TextName1[] = "学习次数:";
    char TextName3[] = "学习率:";

    int Rank = 1;
    int interation = 10;
    double Learning_rat =34.001;

    cleardevice();//清空

    HWND hWnd = GetHWnd();
    SetWindowText(hWnd, "这只是一个普通的窗口名称 O-O");

    setlinecolor(BLACK);
    setfillcolor(BLACK);
    fillrectangle(0, 0, 1024, 5);
    fillrectangle(0, 0, 5, 768);
    fillrectangle(0, 763, 1024, 768);
    fillrectangle(1019, 0, 1024, 768);

    setlinecolor(RGB(124, 124, 124));
    setfillcolor(RGB(234, 234, 234));
    fillrectangle(25, 25, 725, 600);

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
    double_to_string(Learning_rat, &Text3, 3);
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
    while (true)
    {

    }


}
