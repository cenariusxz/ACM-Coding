#include<stdio.h>
#define N 15													//Ԥ���趨ħ�������
int main()
{
	int a[N+2][N+2],i,j,t;										//��չħ�����ֹԽ��
	for (i=1;i<=N;i++)											//�ֽ���������Ԫ�س�ʼ��Ϊ0
	{
		for (j=1;j<=N;j++) a[i][j]=0;
	}
	if (N%2==1)												
	{
		i=1;j=(N+1)/2;											//��ħ�������Ϸ����м��Ԫ�ض�Ϊ1
		a[i][j]=1;
		for (t=2;t<=N*N;t++)									//���չ������ν�ʣ�µ�������ħ������
		{
			i--;
			j++;
			if (i==0&&j<=N)
			{
				i+=N;
				a[i][j]=t;
			}
			else
			{
				if (i>=1&&i<=N&&j==N+1)
				{
					j-=N;
					a[i][j]=t;
				}
				else 
				{
					if (i>=1&&i<=N&&j>=1&&j<=N&&a[i][j]!=0)
					{
						i+=2;
						j--;
						a[i][j]=t;
					}
					else 
					{
						if (i==0&&j==N+1)
						{
							i+=2;
							j--;
							a[i][j]=t;
						}
						else a[i][j]=t;
					}
				}
			}
		}
		for (i=1;i<=N;i++)										//���ħ����
		{
			for (j=1;j<=N;j++) printf("%4d",a[i][j]);
			printf("\n");
		}
	}
	else printf("error!\n");									//��������Ϊ�����򾯸����
	return 0;
}