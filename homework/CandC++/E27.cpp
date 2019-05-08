#include<stdio.h>
#include<string.h>
int main()
{
	char a[20],i,l;
	printf("请输入一个字符串.\n");
	scanf("%s",a);							//输入一个字符串
	l=strlen(a);							//计算字符串长度
	for (i=l-1;i>=0;i--) printf("%c",a[i]);	//逆序输出字符串
	printf("\n");
	return 0;
}