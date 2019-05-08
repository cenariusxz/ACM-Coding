#include<stdio.h>

struct date																//创建结构体
{
	int year;
	int month;
	int day;
}d0={0,0,0};

int sum(int year,int month,int day)										//计算日期与0年0月0日日期差的函数
{
	int m[12]={31,28,31,30,31,30,31,31,30,31,30,31},s=0,i;
	s+=year*365+(year-1)/4-(year-1)/100+(year-1)/400;					//计算中间年份的天数
	for (i=0;i<month-1;i++) s+=m[i];									//计算该年月份的天数
	if ((month>=3)&&((year%400==0)||(year%4==0&&year%100!=0))) s++;
	s+=day;																//计算该月天数
	return s;
}

int main()
{
	int sum1,sum2;
	struct date d1,d2;
	printf("请输入两个日期的年月日。\n");								//提示用户输入
	scanf("%d%d%d%d%d%d",&d1.year,&d1.month,&d1.day,&d2.year,&d2.month,&d2.day);
	sum1=sum(d1.year,d1.month,d1.day);
	sum2=sum(d2.year,d2.month,d2.day);
	printf("相差天数：%d\n",(sum1>sum2)?(sum1-sum2):(sum2-sum1));		//用两日期到0年0月0日的天数做差即为相差天数
	return 0;
}