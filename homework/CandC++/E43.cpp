#include<stdio.h>
#include<string.h>
void delchar(char *p,int k,int n);
int main()
{
	char a[20],*p;
	int k,n;
	printf("������һ���ַ�������k����ʼ��n���ַ�.\n");	//��ʾ�û�����
	scanf("%s%d%d",a,&k,&n);
	p=a;
	delchar(p,k,n);
	return 0;
}

void delchar(char *p,int k,int n)
{
	int len=strlen(p);
	char *q,*s;
	for (q=p+k-1+n;q<=p+len-1;q++) *(q-n)=*q;			//������Ҫ���ַ�ɾ��
	*(p+len-n)='\n';
	printf("%s",p);
}