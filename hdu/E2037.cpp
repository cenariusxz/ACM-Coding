#include<stdio.h>
long long c(int a,int b)
{
	long long i,sum=1,j;
	for (i=a,j=1;i>=a-b+1,j<=b;i--,j++) sum=sum*i/j;
	return sum;
}
int main()
{
	int N;
	while (scanf("%d",&N)!=EOF)
	{
		int i;
		for (i=0;i<N;i++) 
		{
			long long M,j,sum=0;
			scanf("%I64d",&M);
			if (M!=1){
			M--;
			for (j=0;j<=M/2;j++) sum+=c(j+M-j*2,j);
			}
			printf("%I64d\n",sum);
		}
	}
	return 0;
}