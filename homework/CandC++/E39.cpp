#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
void sort(int *,int);
int main()
{
	int a[N+1],n,i,*p;
	srand(time(NULL));
	for (i=0;i<N;i++)							//���������ʼ������
	{
		a[i]=rand();
		printf("%d\t",a[i]);
	}
	printf("������Ҫ�����Ԫ�ظ���.\n");		//��ʾ�û�����
	scanf("%d",&n);
	p=a;
	sort(p,n);
	printf("��ǰ%d���������\n",n);
	for (i=0;i<10;i++) printf("%d\t",a[i]);
	printf("\n");
	return 0;
}

void sort(int *p,int n)
{
	int *q,*s,t;
	for (q=p;q<(p+n);q++)						//����
	{
		for (s=q+1;s<(p+n);s++)
		{
			if (*s<*q)
			{
				t=*s;
				*s=*q;
				*q=t;
			}
		}
	}
}