#include<stdio.h>
#define N 1000
int main()
{
	int prim(int x);
	int i,count=0;
	for (i=2;i<=N;i++)
	{
		if (prim(i)==1)
		{
			printf("%d\t",i);
			count++;
			if (count%8==0) printf("\n");
		}
	}
	return 0;
}

int prim(int x)
{
	int m;
	for (m=x-1;m>=1;m--)
	{
		if (x%m==0) break;
	}
	if (m==1) return 1;
	return 0;
}