#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 7								//Ԥ���趨�������
int main()
{
	int a[N][N],i,j,sum=0;
	srand(time(NULL));
	for (i=0;i<=N-1;i++)				//���������ʼ���������
	{
		for (j=0;j<=N-1;j++)
		{
			a[i][j]=rand();
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	for (i=0;i<=N-1;i++) sum+=a[i][i];	//���㲢��������Խ��ߺ�
	printf("���Խ��ߺ�Ϊ��%d\n",sum);
	for (i=0;i<=N-1;i++) sum+=a[i][N-i];
	printf("���Խ��ߺ�Ϊ��%d\n",sum);
	return 0;
}