#include<stdio.h>
#define N 15													//预先设定魔方阵阶数
int main()
{
	int a[N+2][N+2],i,j,t;										//拓展魔方阵防止越界
	for (i=1;i<=N;i++)											//现将方阵所有元素初始化为0
	{
		for (j=1;j<=N;j++) a[i][j]=0;
	}
	if (N%2==1)												
	{
		i=1;j=(N+1)/2;											//将魔方阵最上方正中间的元素定为1
		a[i][j]=1;
		for (t=2;t<=N*N;t++)									//按照规则依次将剩下的数填入魔方阵中
		{
			i--;
			j++;
			if (i==0&&j<=N)
			{
				i+=N;
				a[i][j]=t;
			}
			else
			{
				if (i>=1&&i<=N&&j==N+1)
				{
					j-=N;
					a[i][j]=t;
				}
				else 
				{
					if (i>=1&&i<=N&&j>=1&&j<=N&&a[i][j]!=0)
					{
						i+=2;
						j--;
						a[i][j]=t;
					}
					else 
					{
						if (i==0&&j==N+1)
						{
							i+=2;
							j--;
							a[i][j]=t;
						}
						else a[i][j]=t;
					}
				}
			}
		}
		for (i=1;i<=N;i++)										//输出魔方阵
		{
			for (j=1;j<=N;j++) printf("%4d",a[i][j]);
			printf("\n");
		}
	}
	else printf("error!\n");									//若阶数不为奇数则警告出错
	return 0;
}