#include<stdio.h>
void msearch(int *,int *);
int main()
{
	int a,b;
	int *p,*q;
	printf("����������������a b.\n");					//��ʾ�û�����
	scanf("%d%d",&a,&b);
	p=&a;
	q=&b;
	msearch(p,q);
	printf("��С������Ϊ:%d\n�������Ϊ:%d\n",*q,*p);
	return 0;
}

void msearch(int *p,int *q)
{
	int a,b,i;
	a=*p;
	b=*q;
	if (a>b)											//��������������
	{
		i=a;
		a=b;
		b=i;
	}
	for (i=a;i>=1;i--)									//Ѱ���������
	{
		if (a%i==0&&b%i==0)
		{
			*p=i;
			break;
		}
	}
	for (i=b;i<=a*b;i++)								//Ѱ����С������
	{
		if (i%a==0&&i%b==0)
		{
			*q=i;
			break;
		}
	}
	return;
}