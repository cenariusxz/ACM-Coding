#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int a[11],i,j,t;
	printf("����ǰ��\n");
	srand(time(NULL));
	for (i=1;i<=10;i++)			//Ϊʮ���������ֵ
	{
		a[i]=rand();
		printf("%d\t",a[i]);
	}
	printf("\n�����\n");
	for (i=1;i<=10;i++)			//��ѡ���������
	{
		for (j=i+1;j<=10;j++)
		{
			if (a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
		printf("%d\t",a[i]);	
	}
	return 0;
}