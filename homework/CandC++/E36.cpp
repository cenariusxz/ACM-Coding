#include<stdio.h>
void msearch(int *,int *);
int main()
{
	int a,b;
	int *p,*q;
	printf("请输入两个正整数a b.\n");					//提示用户输入
	scanf("%d%d",&a,&b);
	p=&a;
	q=&b;
	msearch(p,q);
	printf("最小公倍数为:%d\n最大公因数为:%d\n",*q,*p);
	return 0;
}

void msearch(int *p,int *q)
{
	int a,b,i;
	a=*p;
	b=*q;
	if (a>b)											//对两数进行排序
	{
		i=a;
		a=b;
		b=i;
	}
	for (i=a;i>=1;i--)									//寻找最大公因数
	{
		if (a%i==0&&b%i==0)
		{
			*p=i;
			break;
		}
	}
	for (i=b;i<=a*b;i++)								//寻找最小公倍数
	{
		if (i%a==0&&i%b==0)
		{
			*q=i;
			break;
		}
	}
	return;
}