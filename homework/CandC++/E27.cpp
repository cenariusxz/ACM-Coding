#include<stdio.h>
#include<string.h>
int main()
{
	char a[20],i,l;
	printf("������һ���ַ���.\n");
	scanf("%s",a);							//����һ���ַ���
	l=strlen(a);							//�����ַ�������
	for (i=l-1;i>=0;i--) printf("%c",a[i]);	//��������ַ���
	printf("\n");
	return 0;
}