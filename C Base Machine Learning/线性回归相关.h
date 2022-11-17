#include "界面控制组件.h"

//训练组的存储形式
typedef struct _none {
	double X;
	double Y;
	struct _none* Next;
}Train;

//训练组的增加
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

//目前对应的w[],与b计算出的函数值
double now(double x, double w[], double b, int Rank) {
	double result = 0;
	for (int i = 0; i < Rank; i++) {
		result += w[i] * pow(x, Rank - i);
	}
	return result + b;
}

//依据代价函数对w进行迭代
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

//依据代价函数对b进行迭代
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

//线性回归
void Liner(int interation, double Learning_rat, Train* Head, double w[], double* b, int Rank) {

	for (int i = 0; i < interation; i++) {
		for (int j = 0; j < Rank; j++) {
			w[j] -= Learning_rat * J_1(Head, w, *b, j, Rank);
		}

		(*b) -= Learning_rat * J_2(Head, w, *b, Rank);

		char* Text;
	}
}