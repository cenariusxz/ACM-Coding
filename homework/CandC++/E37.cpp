#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void calcu(int *);
int main()
{
	int a[20],i;
	int *p;
	p=a;
	srand(time(NULL));
	for (;p<a+20;p++)															//用随机数初始化数组并输出
	{
		*p=rand();
		printf("%d\t",*p);
	}
	p=a;
	calcu(p);
	return 0;
}

void calcu(int *p)
{
	int sum=0,max=*p,min=*p,*q;
	float ave=0;
	for (q=p;q<(p+20);q++)														//寻找最大最小值并累加求和
	{
		if (*q<min) min=*q;
		if (*q>max) max=*q;
		sum+=*q;
	}
	ave=float(sum)/20;															//求平均值
	printf("\n总和:%d\n最大值:%d\n最小值:%d\n平均值:%7.2f\n",sum,max,min,ave);
}