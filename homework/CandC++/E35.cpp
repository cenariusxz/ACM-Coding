#include<stdio.h>
int main()
{
	void tran(int x);						//������ת������
	int a;
	printf("������һ��ʮ����������.\n");	//��ʾ�û�����
	scanf("%d",&a);
	printf("ת����Ķ�������Ϊ:\n");
	tran(a);
	printf("\n");
	return 0;
}

void tran(int x)							//������ת������
{
	if (x>1) tran(x/2);
	printf("%d",x%2);
}