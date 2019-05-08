#include<stdio.h>
int main()
{
	int x[10]={13,24,35,46,57,68,79,88,93},i,a,t;
	printf("请输入一个整数.\n");					//提示用户输入
	scanf("%d",&a);
	for (i=8;i>=0;i--)								//从后往前比较并插入数字
	{

		if (a>x[i])
		{
			x[i+1]=a;
			break;
		}
		x[i+1]=x[i];								//如果a比数组里的原数字小，则原数字向后移动一格
	}
	for (i=0;i<=9;i++) printf("%d\t",x[i]);			//输出
	printf("\n");
	return 0;
}