#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
int main()
{
	int s(int a[],int m);
	int a[N],i;
	srand(time(NULL));
	printf("≈≈–Ú«∞£∫\n");
	for (i=0;i<=N-1;i++)
	{
		a[i]=rand();
		printf("%d\t",a[i]);
	}

	return 0;
}