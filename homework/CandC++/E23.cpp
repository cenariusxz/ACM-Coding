#include<stdio.h>
int main()
{
	int x[]={35,46,57,13,24,35,99,68,13,79,88,46},i,j,t;
	for (i=0;i<=10;i++)										//����������������
	{
		for (j=i+1;j<=11;j++)
		{
			if (x[j]<x[i])
			{
				t=x[j];
				x[j]=x[i];
				x[i]=t;
			}
		}
	}
	printf("%d\t",x[0]);
	for (i=1;i<=11;i++)										//ֻ������ظ������������ظ���	
	{
		if (x[i]!=x[i-1]) printf("%d\t",x[i]);
	}
	printf("\n");
	return 0;
}