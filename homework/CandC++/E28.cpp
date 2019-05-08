#include<stdio.h>
int main()
{
	char s1[20],s2[20];
	int len1=0,len2=0,i,j;
	printf("请输入两个字符串s1,s2.\n");			//提示用户输入
	scanf("%s%s",&s1,&s2);
	for (i=0;i<=19;i++)							//通过循环计算两个字符串长度
	{
		if (s1[i]!='\0') len1++;
		if (s2[i]!='\0') len2++;
	}
	for (i=0,j=0;i<=len1;i++)
	{
		if (s1[i]==s2[j]) j++;					//判断s2的元素是否与s1中相同，若相同则继续判断下一个，若不同则从s2中的第一个元素开始重新判断
		else j=0;
		if (j==len2) 
		{
			printf("s1中存在子字符串s2.\n");
			break;
		}
	}
	if (j==0) printf("s1中不存在子字符串s2.\n");
	return 0;
}
