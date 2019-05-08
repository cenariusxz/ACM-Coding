#include<stdio.h>
int main()
{
	void tran(int x);						//二进制转换函数
	int a;
	printf("请输入一个十进制正整数.\n");	//提示用户输入
	scanf("%d",&a);
	printf("转换后的二进制数为:\n");
	tran(a);
	printf("\n");
	return 0;
}

void tran(int x)							//二进制转换函数
{
	if (x>1) tran(x/2);
	printf("%d",x%2);
}