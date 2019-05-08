#include<stdio.h>
void fun(int *);
int main()
{
	int *p,a;
	printf("请输入一个正整数.\n");	//提示用户输入
	scanf("%d",&a);
	p=&a;
	printf("转换后：\n");
	fun(p);
	return 0;
}

void fun(int *p)					//用递归函数将十进制转为二进制并输出
{
	int a=*p;
	if (a>1) 
	{
		*p=a/2;
		fun(p);
	}
	printf("%d",a%2);
}