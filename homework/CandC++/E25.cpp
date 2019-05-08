#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 7								//预先设定方阵阶数
int main()
{
	int a[N][N],i,j,sum=0;
	srand(time(NULL));
	for (i=0;i<=N-1;i++)				//用随机数初始化方阵并输出
	{
		for (j=0;j<=N-1;j++)
		{
			a[i][j]=rand();
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	for (i=0;i<=N-1;i++) sum+=a[i][i];	//计算并输出正负对角线和
	printf("正对角线和为：%d\n",sum);
	for (i=0;i<=N-1;i++) sum+=a[i][N-i];
	printf("负对角线和为：%d\n",sum);
	return 0;
}