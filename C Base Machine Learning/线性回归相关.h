#include "界面控制组件.h"
#define LD 10 //正则化系数的百分比

//训练组的存储形式
typedef struct _none {
	double X;
	double Y;
	struct _none* Next;
}Train;

//对数据进行预处理
void Data_Preprocessing(Train* Head) {
	Train* p = Head;
	while (p) {
		p->X = (p->X-350)/350;
		p->Y = (p->Y-300)/300;
		p = p->Next;
	}
}

//训练组的增加
void Train_append(double x, double y, Train** Head) {
	Train* p = (Train*)malloc(sizeof(Train));
	if (p == NULL) {
		exit(0);
	}
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

//训练组的清空
void Train_free(Train* Head) {
	Train* p;
	if (Head != NULL) {
		while (Head->Next)
		{
			p = Head->Next;
			Head->Next = p->Next;
			free(p);
		}
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

//BGD-梯度下降算法
void B_Gradient_descent(Train* Head, double w[], double* b, int Rank,double Learning_rat,int count) {
	double k,j,Lambda=LD/100*count;

	for (int q = 0; q < Rank; q++) {
		Train* p = Head;
		k = 0;
		j = 0;
		while (p)
		{
			double temp= (now(p->X, w, *b, Rank) - p->Y) / count;
			k += temp;
			j += temp *pow(p->X, Rank - q);
			p = p->Next;
		}
		*b -= Learning_rat * k*10000;
		w[q] -= Learning_rat * (j + Lambda * w[q] / count);
	}

}

//SGD-梯度下降算法
void S_Gradient_descent(Train* Head, double w[], double* b, int Rank, double Learning_rat) {
	double k, j;

	for (int q = 0; q < Rank; q++) {
		Train* p = Head;
		while (p)
		{
			k = (now(p->X, w, *b, Rank) - p->Y);
			j=k* pow(p->X, Rank - q);
			p = p->Next;
			*b -= Learning_rat * k*10000;
			w[q] -= Learning_rat * j ;
		}
	}

}

//线性回归的主体
int Liner(int interation, double Learning_rat, Train* Head, double w[], double* b, int Rank,int count,BOOL Is_BGD) {

	Data_Preprocessing(Head);

	double LR_add = Learning_rat / 100;

	ExMessage msg;
	char TextName[] = "剩余学习次数";
	double* n_w = (double*)malloc(sizeof(double) * Rank);
	double n_b = 9;

	//回归中按钮生成
	char buttonText1[] = "继续";
	button1(50, 650, 200, 50, buttonText1);

	char buttonText2[] = "暂停";
	button1(430, 650, 200, 50, buttonText2);

	char buttonText3[] = "结束回归";
	button1(780, 650, 200, 50, buttonText3);

	if (Is_BGD) {
		button_SGD_OFF(260, 650, 50, 50);
	}
	else
	{
		char buttonText4[] = "SGD";
		button_SGD_ON(260, 650, 50, 50, buttonText4);
	}

	//正式开始回归
	for (int i = 0; i < interation; i++) {

		//回归过程中的可视化
		if (i % 10000 == 0 && i != 0) {

			for (double k = 26; k < 725; k += 0.1) {
				double y = now((k-350)/350, n_w, n_b, Rank) *300+300;
				if (y >= 26 && y <= 599) {
					putpixel(k, y, RGB(234, 234, 234));
				}
			}

			for (double k = 26; k < 725; k += 0.1) {
				double y = now((k-350)/350, w, *b, Rank)*300+300;
				if (y >= 26 && y <= 599) {
					putpixel(k, y, RED);
				}
			}

			n_b = *b;
			for (int i = 0; i < Rank; i++) {
				n_w[i] = w[i];
			}

			char* Text;
			double_to_string((interation - i - 1) / 10000, &Text, 0);
			Inform_show(870, 550, 70, 20, Text, TextName);
			free(Text);

			Train* p = Head;
			while (p)
			{
				setfillcolor(BLACK);
				fillcircle(p->X*350+350, p->Y *300+300, 2);
				p = p->Next;
			}

			if (Learning_rat < LR_add * 1000) {
				Learning_rat += LR_add;
			}

			char TextName8[] = "b:";
			char* Text8;
			if (double_to_string(*b, &Text8, 4)) {
				return 1;
			}
			Text_show(860, 400, 100, 30, Text8, TextName8);
			free(Text8);

			char TextName9[] = "w[最高位]:";
			char* Text9;
			if (double_to_string(w[0], &Text9, 4)) {
				return 1;
			}
			Text_show(860, 450, 100, 30, Text9, TextName9);
			free(Text9);
		}

		//循环读入用户鼠标键盘的相关操作
		if (peekmessage(&msg, EM_MOUSE)) {
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				//暂停按钮
				if (msg.x >= 430 && msg.x <= 630 && msg.y >= 650 && msg.y <= 700) {
					BGM();
					while (true)
					{
						ExMessage msg;
						if (peekmessage(&msg, EM_MOUSE)) {
							switch (msg.message)
							{
							case WM_LBUTTONDOWN:
								//继续按钮
								if (msg.x >= 50 && msg.x <= 250 && msg.y >= 650 && msg.y <= 700)
								{
									BGM();
									goto GoOn;
								}
								//结束线性回归按钮
								if (msg.x >= 780 && msg.x <= 980 && msg.y >= 650 && msg.y <= 700)
								{
									BGM();
									goto Next;
								}
								break;
							default:
								break;
							}
						}
					}
				}

				//线性回归结束按钮
				if (msg.x >= 780 && msg.x <= 980 && msg.y >= 650 && msg.y <= 700)
				{
					BGM();
					goto Next;
				}
				break;
			default:
				break;
			}
		}

	GoOn:

		//与阶数相关的循环线性回归
		if (Is_BGD) {
			//使用BGD梯度下降方法
			B_Gradient_descent(Head, w, b, Rank, Learning_rat, count);
		}
		else {
			//使用SGD梯度下降方法（随机梯度下降）
			S_Gradient_descent(Head, w, b, Rank, Learning_rat);
		}
		
	}

Next:

	Inform_delete(870, 550, 70, 20,TextName);
	return 0;

}
