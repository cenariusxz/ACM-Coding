#include<stdio.h>
int main()
{
	int month;
	printf("�������·�.\n");							//��ʾ�û�����
	scanf("%d",&month);							//�����·�
	switch(month)										//���·��������
	{
		case(1):
		case(3):
		case(5):
		case(7):
		case(8):
		case(10):
		case(12):printf("31days.\n");break;
		case(2):printf("28days.\n");break;
		default:printf("30days.\n");
	}
	return 0;
}