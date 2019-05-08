#include<stdio.h>
#include<string.h>
int main()
{
	int i,len;
	char s[40];
	printf("请输入一个英文句子.\n");
	gets(s);
	len=strlen(s);
	if (s[0]!=' '&&s[0]!=';'&&s[0]!=','&&s[0]!='.') printf("%c",s[0]);
	for (i=1;i<=len-1;i++)
	{
		if (s[i]!=' '&&s[i]!=';'&&s[i]!=','&&s[i]!='.') printf("%c",s[i]);
		else 
		{
			if (s[i-1]!=' '&&s[i-1]!=';'&&s[i-1]!=','&&s[i-1]!='.') printf("\n");
		}
	}
	printf("\n");
	return 0;
}