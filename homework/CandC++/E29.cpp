#include<stdio.h>
#include<string.h>
int main()
{
	int i,len;
	char s[40];
	printf("������һ��Ӣ�ľ���.\n");												//��ʾ�û�����
	gets(s);
	len=strlen(s);																	//�����ַ�������
	if (s[0]!=' '&&s[0]!=';'&&s[0]!=','&&s[0]!='.') printf("%c",s[0]);				//�жϵ�һ���ַ��Ƿ�Ϊ�ָ����������������
	for (i=1;i<=len-1;i++)															//ѭ���ж����ַ����Ƿָ�����������ַ������Ƿָ�����ǰһ���ַ�������������з�
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