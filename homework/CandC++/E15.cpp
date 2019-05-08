#include<stdio.h>
int main()
{
	int i,t;
	for (i=32,t=1;i<=126;i++,t++)
	{
		putchar(i);
		printf("\t");
		if (t%5==0) printf("\n");
	}
	return 0;
}