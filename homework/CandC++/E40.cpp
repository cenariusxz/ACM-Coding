#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
void sort(int *,int);
void ins(int *,int,int);
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
	for (i=0;i<N;i++) printf("%d\t",a[i]);
	printf("\n");
	int m;
	printf("������Ҫ�����������.\n");			//��ʾ�û�����
	scanf("%d",&m);
	ins(p,n,m);
	printf("��������Ľ����\n");
	for (i=0;i<N+1;i++) printf("%d\t",a[i]);
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

void ins(int *p,int n,int m)
{
	int *q,*s;
	for (q=p+N-1;q>=p+n;q--) *(q+1)=*q;			//��δ����������������һλ
	q=p+n-1;
	if (m>*q) *(q+1)=m;							//�ж�Ҫ��������Ƿ�Ϊ������
	else										//��������������
	{
		for (;q>=p+1;q--)
		{
			*(q+1)=*q;
			if (m>*(q-1))
			{
				*q=m;
				break;
			}
		}
	}
}