#include "�ļ����.h"

//���Իع���ʾ����
void Linear_regression_presentaion() {

    //��������
    initgraph(1024, 768);//�����ֱ���
    setbkcolor(WHITE);//������ɫ

Ori:
    cleardevice();//���

    //��ʼ��
    char TextName2[] = "��Ͻ���:";
    char TextName1[] = "ѧϰ����:";
    char TextName3[] = "ѧϰ��:";

    BOOL Is_BGD = true;
    int count = 0;//���ݼ������ݸ���
    int Rank = 1;
    int interation = 100000;
    double Learning_rat =1;
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
    SetWindowText(hWnd, "��ֻ��һ����ͨ�Ĵ������� O-O");

Again:

    char buttonText1[] = "��ʼ���Իع�";
    button(50, 650, 200, 50, buttonText1);

    char buttonText2[] = "��ʼ��";
    button(430, 650, 200, 50, buttonText2);

    char buttonText3[] = "��������";
    button(780, 650, 200, 50, buttonText3);

    char buttonText4[] = "SGD";
    button(260, 650, 50, 50, buttonText4);

    char* Text1;
    IntToString(interation, &Text1);
    Text_show(860, 100, 100, 30, Text1, TextName1);

    char* Text2;
    IntToString(Rank, &Text2);
    Text_show(860, 200, 100, 30, Text2, TextName2);

    char* Text3;
    double_to_string(Learning_rat, &Text3, 5);
    Text_show(860, 300, 100, 30, Text3, TextName3);
    
    //ѭ�������û������̵���ز���
    while (true)
    {
        ExMessage msg;
        setlinecolor(BLACK);
        setfillcolor(BLACK);

        if (peekmessage(&msg, EM_MOUSE)) {
            switch (msg.message)
            {
            case WM_LBUTTONDOWN:

                //����ѵ��������
                if (msg.x >= 25 && msg.x <= 725 && msg.y >= 25 && msg.y <= 600) {
                    fillcircle(msg.x, msg.y, 2);
                    Train_append(msg.x-325, msg.y-325, &Head);
                    count++;
                }
                //��ʼ����ť
                if (msg.x >= 430 && msg.x <= 630 && msg.y >= 650 && msg.y <= 700) {
                    BGM();
                    goto Ori;
                }
                //����BGD�㷨�����Իع鿪ʼ��ť
                if (msg.x >= 50 && msg.x <= 250 && msg.y >= 650 && msg.y <= 700)
                {
                    BGM();
                    Is_BGD = true;
                    goto Next;
                }
                //����SGD�㷨�����Իع鿪ʼ��ť
                if (msg.x >= 260 && msg.x <= 310 && msg.y >= 650 && msg.y <= 700)
                {
                    BGM();
                    Is_BGD = false;
                    goto Next;
                }
                //�˳���Ϸ��ť
                if (msg.x >= 780 && msg.x <= 980 && msg.y >= 650 && msg.y <= 700)
                {
                    closegraph();
                    BGM();
                    Sleep(2000);
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

//��ʽ��ʼ���Իع���ʾ
Next:
    

    //��ʼ��w[]��b
    double* w = (double*)malloc(sizeof(double) * Rank);
    double b = 1;
    for (int i = 0; i < Rank; i++) {
        w[i] = 1;
    }

    //���Իع�ʵ��
    Liner(10000*interation, 0.000001*Learning_rat, Head, w, &b,Rank,count,Is_BGD);

    char TextName8[] = "b:";
    char* Text8;
    double_to_string(b, &Text8, 4);
    Text_show(860, 400, 100, 30, Text8, TextName8);

    char TextName9[] = "w[���λ]:";
    char* Text9;
    double_to_string(w[0], &Text9, 4);
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

    //ȷ���������Ϸ�
    Train* p = Head;
    while (p)
    {
        setlinecolor(BLACK);
        setfillcolor(BLACK);
        fillcircle(p->X + 325, p->Y + 325, 2);
        p = p->Next;
    }

    FileOutput(w, b, Rank);

    free(w);

    goto Again;
}
