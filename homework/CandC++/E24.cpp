#include<stdio.h>
#define N 8													//Ԥ���趨������ǽ���Ϊ8
int main()
{
	int a[N][N],i,j;
	for (i=0;i<=N-1;i++)									//��������������������ֶ�Ϊ1
	{
		a[i][0]=1;
		a[i][i]=1;
	}
	for (i=2;i<=N-1;i++)									//����ѭ�������������м����
	{
		for (j=1;j<=i-1;j++) a[i][j]=a[i-1][j-1]+a[i-1][j];
	}
	for (i=0;i<=N-1;i++)									//����������
	{
		for (j=0;j<=i;j++) printf("%3d",a[i][j]);
		printf("\n");
	}
	return 0;
}