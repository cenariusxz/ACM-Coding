#include<stdio.h>
void fun(int *);
int main()
{
	int *p,a;
	printf("������һ��������.\n");	//��ʾ�û�����
	scanf("%d",&a);
	p=&a;
	printf("ת����\n");
	fun(p);
	return 0;
}

void fun(int *p)					//�õݹ麯����ʮ����תΪ�����Ʋ����
{
	int a=*p;
	if (a>1) 
	{
		*p=a/2;
		fun(p);
	}
	printf("%d",a%2);
}