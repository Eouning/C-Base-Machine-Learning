#include "����������.h"

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
	w[px] -= Learning_rat * k;

}

//���Իع�
void Liner(int interation, double Learning_rat, Train* Head, double w[], double* b, int Rank,int count) {
	char TextName[] = "ʣ��ѧϰ����";
	double* n_w = (double*)malloc(sizeof(double) * Rank);
	double n_b = 9;

	for (int i = 0; i < interation; i++) {

		if (i % 10000 == 0 && i != 0) {

			for (double k = 26; k < 725; k++) {
				double y = now(k-325, n_w, n_b, Rank)+325;
				if (y >= 26 && y <= 599) {
					putpixel(k, y, RGB(234, 234, 234));
				}
			}

			for (double k = 26; k < 725; k++) {
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
		}

		for (int j = 0; j < Rank; j++) {
			Gradient_descent(Head, w, b, j, Rank,Learning_rat,count);
		}

	}

	Inform_delete(870, 550, 70, 20,TextName);
}