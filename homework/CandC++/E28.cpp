#include<stdio.h>
int main()
{
	char s1[20],s2[20];
	int len1=0,len2=0,i,j;
	printf("�����������ַ���s1,s2.\n");			//��ʾ�û�����
	scanf("%s%s",&s1,&s2);
	for (i=0;i<=19;i++)							//ͨ��ѭ�����������ַ�������
	{
		if (s1[i]!='\0') len1++;
		if (s2[i]!='\0') len2++;
	}
	for (i=0,j=0;i<=len1;i++)
	{
		if (s1[i]==s2[j]) j++;					//�ж�s2��Ԫ���Ƿ���s1����ͬ������ͬ������ж���һ��������ͬ���s2�еĵ�һ��Ԫ�ؿ�ʼ�����ж�
		else j=0;
		if (j==len2) 
		{
			printf("s1�д������ַ���s2.\n");
			break;
		}
	}
	if (j==0) printf("s1�в��������ַ���s2.\n");
	return 0;
}
