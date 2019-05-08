#include<stdio.h>
int main()
{
	int x[100],i,j,count=0;
	for (i=1;i<=99;i++) x[i]=0;							//将所有数都先表成素数，再通过筛法将素数的倍数筛除
	for (i=1;i<=99;i++)
	{
		if (x[i]==0)									//先判断是否已被定为非素数
		{
			for (j=i;j>=1;j--)							//判断是否为素数
			{
				if ((i+1)%j==0) break;
			}
			if (j==1)									//是素数则本身不变，将其倍数定为非素数
			{
				for (j=i+i+1;j<=99;j+=(i+1)) x[j]=1;
			}
		}
	}
	for (i=1;i<=99;i++)									//按照一行5个数的格式输出所有素数
	{
		if (x[i]==0) 
		{
			printf("%d\t",i+1);
			count++;
			if (count%5==0) printf("\n");
		}
	}
	return 0;
}