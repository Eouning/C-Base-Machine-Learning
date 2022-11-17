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

//���ݴ��ۺ�����w���е���
double J_1(Train* Head, double w[], double b, int px, int Rank) {
	double j = 0;
	Train* p = Head;
	int NUM = 0;

	while (p)
	{
		j += (now(p->X, w, b, Rank) - p->Y) * pow(p->X, Rank - px);
		NUM++;
		p = p->Next;
	}

	return j/NUM;
}

//���ݴ��ۺ�����b���е���
double J_2(Train* Head, double w[], double b, int Rank) {
	double j = 0;
	int NUM = 0;
	Train* p = Head;

	while (p)
	{
		j += (now(p->X, w, b, Rank) - p->Y);
		NUM++;
		p = p->Next;
	}

	return j /NUM;
}

//���Իع�
void Liner(int interation, double Learning_rat, Train* Head, double w[], double* b, int Rank) {

	for (int i = 0; i < interation; i++) {
		for (int j = 0; j < Rank; j++) {
			w[j] -= Learning_rat * J_1(Head, w, *b, j, Rank);
		}

		(*b) -= Learning_rat * J_2(Head, w, *b, Rank);

		char* Text;
	}
}