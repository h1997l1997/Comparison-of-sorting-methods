#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 30000

int GuanJianZi[7];
int PaiXu[7];
int ShuZu1[N] = { 0 };
int ShuZu2[N + 1] = { 0 };

void ZhiJieChaRu(int R[], int n);
void JianDanXuanZe(int R[], int n);
void MaoPao(int R[], int n);
void KuaiSuPaiXu(int R[], int low, int high);
void XiEr(int R[], int m, int n);
void XiEr2(int R[], int n);
void Merge(int R[], int low, int mid, int high);
void MSort(int R[], int low, int high);
void result(int R[], int n);


int main()
{
	printf("实验一：约瑟夫斯问题求解\n姓名：张世博\n学号：031620316\n=========Enter开始程序==========\n");
	system("pause");
	int i, j, ShuZu0[N + 1];
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("Current local time and date:%s\n", asctime(timeinfo));
	printf("内部排序算法的实现与比较\n");
	for (i = 1; i <= N; i++)
	{
		ShuZu0[i] = rand() % 1000 + 1;
	}
	do
	{
		int a;
		for (a = 1; a < N + 1; a++) {
			ShuZu1[a] = ShuZu0[a];
			ShuZu2[a] = ShuZu0[a];
		}
		printf("请选择所需排序方法：");
		printf("\n");
		printf("1.插入法	2.选择法	3.冒泡法\n4.快速法	5.希尔排序法	6.归并排序法\n7.排序关键字大小	8.退出\n");
		scanf("%d", &j);
		switch (j)
		{
		case 1:
			ZhiJieChaRu(ShuZu2, N);
			printf("直接插入排序关键字参加的比较次数：%d,关键字的移动次数：%d\n", PaiXu[1], GuanJianZi[1]);
			printf("\n");
			break;
		case 2:
			JianDanXuanZe(ShuZu2, N);
			printf("直接选择排序关键字参加的比较次数：%d,关键字的移动次数：%d\n", PaiXu[2], GuanJianZi[2]);
			printf("\n");
			break;
		case 3:
			MaoPao(ShuZu2, N);
			printf("冒泡排序关键字参加的比较次数：%d,关键字的移动次数：%d\n", PaiXu[3], GuanJianZi[3]);
			printf("\n");
			break;
		case 4:
			KuaiSuPaiXu(ShuZu2, 1, N);
			printf("快速排序关键字参加的比较次数：%d,关键字的移动次数：%d\n", PaiXu[4], GuanJianZi[4]);
			printf("\n");
			break;
		case 5:
			XiEr2(ShuZu2, N);
			printf("希尔排序关键字参加的比较次数：%d,关键字的移动次数：%d\n", PaiXu[5], GuanJianZi[5]);
			printf("\n");
			break;
		case 6:
			MSort(ShuZu2, 1, N);
			printf("归并排序关键字参加的比较次数：%d,关键字的移动次数：%d\n", PaiXu[6], GuanJianZi[6]);
			printf("\n");
			break;
		case 7:
			result(PaiXu, 6);
			result(GuanJianZi, 6);
			printf("关键字参加的比较次数:\n");
			for (i = 1; i <= 6; i++)
				printf("%d\t", PaiXu[i]);
			printf("\n");
			printf("关键字的移动次数：\n");
			for (i = 1; i <= 6; i++)
				printf("%d\t", GuanJianZi[i]);
			printf("\n");
			break;


		case 8:
			printf("Current local time and date:%s", asctime(timeinfo));
			exit(0);
			break;
		}
	} while (1);
}

void ZhiJieChaRu(int R[], int n)							//直接插入排序
{
	int i, j;
	for (i = 2; i <= n; i++)
	{
		R[0] = R[i];
		j = i - 1;
		while (R[0]<R[j])
		{
			R[j + 1] = R[j];
			j--;
			GuanJianZi[1]++;
		}
		PaiXu[1]++;
		R[j + 1] = R[0];
		GuanJianZi[1] += 2;
	}
}

void JianDanXuanZe(int R[], int n)							//简单选择排序
{
	int i, j, k;
	for (i = 1; i<n; i++)
	{
		k = i;
		for (j = i + 1; j <= n; j++)
		{
			if (R[j]<R[k]) k = j;
			PaiXu[2]++;
		}
		if (k != i)
		{
			R[0] = R[k];
			R[k] = R[i];
			R[i] = R[0];
			GuanJianZi[2] += 3;
		}
	}
}

void MaoPao(int R[], int n)							//冒泡排序
{
	int i, j, flag = 0;
	for (i = 1; (i<n&&flag == 0); i++)
	{
		flag = 1;
		for (j = 1; j <= n - i; j++)
		{
			if (R[j + 1]<R[j])
			{
				flag = 0;
				R[0] = R[j];
				R[j] = R[j + 1];
				R[j + 1] = R[0];
				GuanJianZi[3] += 3;
			}
			PaiXu[3]++;
		}
	}
}

void KuaiSuPaiXu(int R[], int low, int high)				//快速排序
{
	int i, j;
	i = low;
	j = high;
	R[0] = R[i];
	GuanJianZi[4]++;
	while (i<j)
	{
		while (R[j] >= R[0] && (j>i))
		{
			j--;
		}
		PaiXu[4]++;
		if (j>i)
		{
			R[i] = R[j];
			GuanJianZi[4]++;
			i++;
		}
		while (R[i] <= R[0] && (j>i))
		{
			i++;
			PaiXu[4]++;
		}
		if (j>i)
		{
			R[j] = R[i];
			GuanJianZi[4]++;
			j--;
		}
	}
	R[i] = R[0];
	GuanJianZi[4]++;
	if (i>low)
		KuaiSuPaiXu(R, low, i - 1);
	if (i<high)
		KuaiSuPaiXu(R, j + 1, high);
}

void XiEr(int R[], int m, int n)				//一趟希尔排序，按间隔划分子序列
{
	int i, j, temp;
	for (i = m; i <= n; i++)
	{
		temp = R[i];
		j = i;
		while (j >= m&&temp<R[j - m])
		{
			PaiXu[5]++;
			R[j] = R[j - m];
			j -= m;
			GuanJianZi[5]++;
		}
		R[j] = temp;
		GuanJianZi[5]++;
	}
}

void XiEr2(int R[], int n)						//希尔排序
{
	int m, y;
	m = n / 2;
	while (m >= 1)										//循环直到m为0
	{
		XiEr(R, m, n);
		m = (m == 2 ? 1 : (m / 2));							//缩小增进量
	}
	printf("关键字参加的比较次数：%d,关键字的移动次数：%d\n", PaiXu[5], GuanJianZi[5]);
	printf("\n");
}

void Merge(int R[], int low, int mid, int high)
{
	int i, j, k;
	int n1, n2;
	i = low;
	j = mid + 1;
	k = low;
	while (i <= mid&&j <= high)									//两两比较
	{
		if (R[i] <= R[j])
		{
			ShuZu1[k] = R[i];
			i++;
			k++;
		}
		else
		{
			ShuZu1[k] = R[j];
			j++;
			k++;
		}
		PaiXu[6]++;
		GuanJianZi[6]++;
	}
	if (i <= mid)
		for (n1 = k, n2 = i; n1 <= high&&n2 <= mid; n1++, n2++)
		{
			ShuZu1[n1] = R[n2];
			GuanJianZi[6]++;
		}
	else
		for (n1 = k, n2 = j; n1 <= high&&n2 <= high; n1++, n2++)
		{
			ShuZu1[n1] = R[n2];
			GuanJianZi[6]++;
		}
	for (mid = low; mid <= high; mid++)
	{
		R[mid] = ShuZu1[mid];
		GuanJianZi[6]++;
	}
}

void MSort(int R[], int low, int high)						//归并排序
{
	int mid;
	if (low<high)
	{
		mid = (low + high) / 2;
		MSort(R, low, mid);
		MSort(R, mid + 1, high);
		Merge(R, low, mid, high);
	}
}

void result(int R[], int n)			//排序最后的结果
{
	int i, j, flag = 0;
	for (i = 1; (i<n&&flag == 0); i++)
	{
		flag = 1;
		for (j = 1; j <= n - i; j++)
			if (R[j + 1]<R[j])
			{
				flag = 0;
				R[0] = R[j];
				R[j] = R[j + 1];
				R[j + 1] = R[0];
			}
	}
}




