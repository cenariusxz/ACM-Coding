#include<stdio.h>
int main()
{
	char ch;
	printf("请从键盘上输入一个小写字母.\n");
	ch=getchar();
	ch=ch-32;
	putchar(ch);
	printf("\n");
	return 0;
}