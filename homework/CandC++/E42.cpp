#include<stdio.h>
#include<string.h>
void dec(char *);
int main()
{
	char a[20],*p;
	printf("������һ���ַ���.\n");			//��ʾ�û�����
	scanf("%s",a);
	p=a;
	dec(p);
	return 0;
}

void dec(char *p)
{
	int len,i;
	char b[20]="\0";						//��ʼ���ַ���b
	len=strlen(p);
	for (i=0;i<len;i++) b[len-i-1]=*(p+i);	//���ַ���a��ת��ֵ��b
	if (strcmp(p,b)==0) printf("TRUE\n");	//�ж�a��b�Ƿ���ͬ
	else printf("FALSE\n");
}