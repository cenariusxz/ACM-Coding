#include<stdio.h>
int main()
{
	int count=0,i,t;
	for(i=0;i<=50/5;i++)
	{
		t=(50-5*i)/2+1;
		count=count+t;
	}
	printf("����%d����Ϸ�ʽ.\n",count);
	return 0;
}