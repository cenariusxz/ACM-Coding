#include<stdio.h>
int main()
{
	int count=0,i,t;
	for(i=0;i<=50/5;i++)
	{
		t=(50-5*i)/2+1;
		count=count+t;
	}
	printf("共有%d种组合方式.\n",count);
	return 0;
}