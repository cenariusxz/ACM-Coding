#include<stdio.h>
#include<string.h>
void delchar(char *p,int k,int n);
int main()
{
	char a[20],*p;
	int k,n;
	printf("请输入一个字符串，第k个开始的n个字符.\n");	//提示用户输入
	scanf("%s%d%d",a,&k,&n);
	p=a;
	delchar(p,k,n);
	return 0;
}

void delchar(char *p,int k,int n)
{
	int len=strlen(p);
	char *q,*s;
	for (q=p+k-1+n;q<=p+len-1;q++) *(q-n)=*q;			//将不需要的字符删除
	*(p+len-n)='\n';
	printf("%s",p);
}