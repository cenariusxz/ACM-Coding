#include<stdio.h>
int main()
{
	int a,b,c,max;
	printf("请输入三个整数a b c.\n");
	scanf("%d%d%d",&a,&b,&c);
	if (a>b)
	{if (a>c) max=a;
	else max=c;
	}
	else
	{if (b>c) max=b;
	else max=c;
	}
	printf("max=%d\n",max);
	return 0;
}