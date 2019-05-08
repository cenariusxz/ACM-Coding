#include<stdio.h>
#define N 8													//预先设定杨辉三角阶数为8
int main()
{
	int a[N][N],i,j;
	for (i=0;i<=N-1;i++)									//将杨辉三角两条边上数字定为1
	{
		a[i][0]=1;
		a[i][i]=1;
	}
	for (i=2;i<=N-1;i++)									//利用循环算出杨辉三角中间的数
	{
		for (j=1;j<=i-1;j++) a[i][j]=a[i-1][j-1]+a[i-1][j];
	}
	for (i=0;i<=N-1;i++)									//输出杨辉三角
	{
		for (j=0;j<=i;j++) printf("%3d",a[i][j]);
		printf("\n");
	}
	return 0;
}