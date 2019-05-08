#include<stdio.h>
int main()
{
	int N,i;
	long long a[50];
	a[0]=3;
	a[1]=6;
	a[2]=6;
	for (i=3;i<50;i++) a[i]=a[i-1]+2*a[i-2];
	while (scanf("%d",&N)!=EOF)
	{
		printf("%I64d\n",a[N-1]);
	}
	return 0;
}