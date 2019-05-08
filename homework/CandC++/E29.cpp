#include<stdio.h>
#include<string.h>
int main()
{
	int i,len;
	char s[40];
	printf("请输入一个英文句子.\n");												//提示用户输入
	gets(s);
	len=strlen(s);																	//计算字符串长度
	if (s[0]!=' '&&s[0]!=';'&&s[0]!=','&&s[0]!='.') printf("%c",s[0]);				//判断第一个字符是否为分隔符，若不是则输出
	for (i=1;i<=len-1;i++)															//循环判断若字符不是分隔符则输出该字符，若是分隔符且前一个字符不是则输出换行符
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