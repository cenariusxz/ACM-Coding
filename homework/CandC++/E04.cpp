#include<stdio.h>
int main()
{
	int a,b,c,d,sum;
	printf("请输入一个三位正整数.\n");
	scanf("%d",&a);
	b=a/100;
	c=a/10-10*b;
	d=a-100*b-10*c;
	sum=b+c+d;
	printf("sum=%d\n",sum);
	return 0;
}