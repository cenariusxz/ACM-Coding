#include<stdio.h>

struct date																//�����ṹ��
{
	int year;
	int month;
	int day;
}d0={0,0,0};

int sum(int year,int month,int day)										//����������0��0��0�����ڲ�ĺ���
{
	int m[12]={31,28,31,30,31,30,31,31,30,31,30,31},s=0,i;
	s+=year*365+(year-1)/4-(year-1)/100+(year-1)/400;					//�����м���ݵ�����
	for (i=0;i<month-1;i++) s+=m[i];									//��������·ݵ�����
	if ((month>=3)&&((year%400==0)||(year%4==0&&year%100!=0))) s++;
	s+=day;																//�����������
	return s;
}

int main()
{
	int sum1,sum2;
	struct date d1,d2;
	printf("�������������ڵ������ա�\n");								//��ʾ�û�����
	scanf("%d%d%d%d%d%d",&d1.year,&d1.month,&d1.day,&d2.year,&d2.month,&d2.day);
	sum1=sum(d1.year,d1.month,d1.day);
	sum2=sum(d2.year,d2.month,d2.day);
	printf("���������%d\n",(sum1>sum2)?(sum1-sum2):(sum2-sum1));		//�������ڵ�0��0��0�յ��������Ϊ�������
	return 0;
}