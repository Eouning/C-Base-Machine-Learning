#include "����������.h"

#define Lambda 10//���򻯲���

//ѵ����Ĵ洢��ʽ
typedef struct _none {
	double X;
	double Y;
	struct _none* Next;
}Train;

//ѵ���������
void Train_append(double x, double y, Train** Head) {
	Train* p = (Train*)malloc(sizeof(Train));
	p->X = x;
	p->Y = y;
	p->Next = NULL;

	Train* ph = *Head;
	if (*Head == NULL) {
		*Head = p;
	}
	else
	{
		while (ph->Next)
		{
			ph = ph->Next;
		}
		ph->Next = p;
	}

}

//Ŀǰ��Ӧ��w[],��b������ĺ���ֵ
double now(double x, double w[], double b, int Rank) {
	double result = 0;
	for (int i = 0; i < Rank; i++) {
		result += w[i] * pow(x, Rank - i);
	}
	return result + b;
}

//�ݶ��½��㷨
void Gradient_descent(Train* Head, double w[], double* b, int px, int Rank,double Learning_rat,int count) {
	double j = 0,k=0;
	Train* p = Head;

	while (p)
	{
		double i = (now(p->X, w, *b, Rank) - p->Y)/count;
		j += i;
		k += i * pow(p->X, Rank - px);
		p = p->Next;
	}

	*b-= Learning_rat*j;
	w[px] -= Learning_rat * (k+Lambda*w[px]/count);

}

//���Իع�
void Liner(int interation, double Learning_rat, Train* Head, double w[], double* b, int Rank,int count) {

	ExMessage msg;
	char TextName[] = "ʣ��ѧϰ����";
	double* n_w = (double*)malloc(sizeof(double) * Rank);
	double n_b = 9;

	//�ع��а�ť����
	char buttonText1[] = "����";
	button1(50, 650, 200, 50, buttonText1);

	char buttonText2[] = "��ͣ";
	button1(430, 650, 200, 50, buttonText2);

	char buttonText3[] = "�����ع�";
	button1(780, 650, 200, 50, buttonText3);

	//��ʽ��ʼ�ع�
	for (int i = 0; i < interation; i++) {

		//�ع�����еĿ��ӻ�
		if (i % 10000 == 0 && i != 0) {

			for (double k = 26; k < 725; k+=0.1) {
				double y = now(k-325, n_w, n_b, Rank)+325;
				if (y >= 26 && y <= 599) {
					putpixel(k, y, RGB(234, 234, 234));
				}
			}

			for (double k = 26; k < 725; k+=0.1) {
				double y = now(k-325, w, *b, Rank)+325;
				if (y >= 26 && y <= 599) {
					putpixel(k, y, RED);
				}
			}

			n_b = *b;
			for (int i = 0; i < Rank; i++) {
				n_w[i] = w[i];
			}

			char* Text;
			double_to_string((interation-i-1)/10000, &Text, 0);
			Inform_show(870, 550, 70, 20, Text,TextName);
			free(Text);

			Train* p = Head;
			while (p)
			{
				setfillcolor(BLACK);
				fillcircle(p->X+325, p->Y+325, 2);
				p = p->Next;
			}
		}
		
		//ѭ�������û������̵���ز���
		if (peekmessage(&msg, EM_MOUSE)) {
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 430 && msg.x <= 630 && msg.y >= 650 && msg.y <= 700) {
					while (true)
					{
						ExMessage msg;
						if (peekmessage(&msg, EM_MOUSE)) {
							switch (msg.message)
							{
							case WM_LBUTTONDOWN:
								if (msg.x >= 50 && msg.x <= 250 && msg.y >= 650 && msg.y <= 700)
								{
									goto GoOn;
								}
								if (msg.x >= 780 && msg.x <= 980 && msg.y >= 650 && msg.y <= 700)
								{
									goto Next;
								}
								break;
							default:
								break;
							}
						}
					}
				}
				if (msg.x >= 780 && msg.x <= 980 && msg.y >= 650 && msg.y <= 700)
				{
					goto Next;
				}
				break;
			default:
				break;
			}
		}

	GoOn:

		//�������ص�ѭ�����Իع�
		for (int j = 0; j < Rank; j++) {
			Gradient_descent(Head, w, b, j, Rank,Learning_rat,count);
		}
	}

Next:

	Inform_delete(870, 550, 70, 20,TextName);

}