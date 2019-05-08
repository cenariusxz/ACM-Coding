#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
int main()
{
	int a[N],i;
	int max(int x[],int);
	srand(time(NULL));
	for (i=0;i<=N-1;i++) 
	{
		a[i]=rand();
		printf("%d\t",a[i]);
	}
	printf("\n最大值为%d",max(a,N));
	return 0;
}

int max(int x[],int len)
{
	int max,i;
	max=x[0];
	for (i=1;i<=len;i++) if (x[i]>max) max=x[i];
	return max;
}