#include<stdio.h>
int main()
{
	float a1=1,a2=2,t,S=0;
	int i;
	for (i=1;i<=20;i++)
	{
		t=a1/a2;
		S=S+t;
		t=a2;
		a2=a1+a2;
		a1=t;
	}
	printf("S=%10.4f\n",S);
	return 0;
}