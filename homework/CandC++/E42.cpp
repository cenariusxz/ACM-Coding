#include<stdio.h>
#include<string.h>
void dec(char *);
int main()
{
	char a[20],*p;
	printf("请输入一个字符串.\n");			//提示用户输入
	scanf("%s",a);
	p=a;
	dec(p);
	return 0;
}

void dec(char *p)
{
	int len,i;
	char b[20]="\0";						//初始化字符串b
	len=strlen(p);
	for (i=0;i<len;i++) b[len-i-1]=*(p+i);	//将字符串a翻转赋值给b
	if (strcmp(p,b)==0) printf("TRUE\n");	//判断a，b是否相同
	else printf("FALSE\n");
}