#include<stdio.h>
int main()
{
	int a,b,x1,x2,t,i;
	printf("����������������a b.\n");				//��ʾ�û�����
	scanf("%d%d",&a,&b);
	if (a>b)										//���Ƚ�a,b����С˳������
	{
		t=a;
		a=b;
		b=t;
	}
	for (i=a;i>=1;i--)								//��С����1���ж��������
	{
		if (!(a%i)&&!(b%i)) 
		{
			x1=i;
			break;
		}
	}
	for (i=b;i<=a*b;i++)							//�Ӵ����������˻�����С������
	{
		if (!(i%a)&&!(i%b)) 
		{
			x2=i;
			break;
		}
	}
	printf("�������=%d\n��С������=%d\n",x1,x2);	//���
	return 0;
}