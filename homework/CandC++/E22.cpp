#include<stdio.h>
int main()
{
	int x[10]={13,24,35,46,57,68,79,88,93},i,a,t;
	printf("������һ������.\n");					//��ʾ�û�����
	scanf("%d",&a);
	for (i=8;i>=0;i--)								//�Ӻ���ǰ�Ƚϲ���������
	{

		if (a>x[i])
		{
			x[i+1]=a;
			break;
		}
		x[i+1]=x[i];								//���a���������ԭ����С����ԭ��������ƶ�һ��
	}
	for (i=0;i<=9;i++) printf("%d\t",x[i]);			//���
	printf("\n");
	return 0;
}