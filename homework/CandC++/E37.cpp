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
	for (;p<a+20;p++)															//���������ʼ�����鲢���
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
	for (q=p;q<(p+20);q++)														//Ѱ�������Сֵ���ۼ����
	{
		if (*q<min) min=*q;
		if (*q>max) max=*q;
		sum+=*q;
	}
	ave=float(sum)/20;															//��ƽ��ֵ
	printf("\n�ܺ�:%d\n���ֵ:%d\n��Сֵ:%d\nƽ��ֵ:%7.2f\n",sum,max,min,ave);
}