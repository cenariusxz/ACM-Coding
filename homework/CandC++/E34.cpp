#include<stdio.h>
#include<string.h>
int main()
{
	int tran(char a[],int len),len,i,m=1;
	char a[10];
	printf("������һ����0~9���ɵ��ַ���.\n");		//��ʾ�û�����
	gets(a);
	len=strlen(a);									//�����ַ�������
	for (i=0;i<=len-1;i++)							//���ж������ʽ�Ƿ�����������m��ֵΪ0��������Ϊ1
	{
		if (a[i]<48||a[i]>58)
		{
			m=0;
			break;
		}
	}
	if (m==0) printf("error!\n");					//����������������棬�������ת�����
	else printf("ת����Ľ��:\n%d\n",tran(a,len));
	return 0;
}

int tran(char a[],int len)							//ת������
{
	int i,j,m,sum=0;
	for (i=0;i<=len-1;i++)
	{
		m=a[i]-48;
		for (j=i+1;j<=len-1;j++) m=m*10;
		sum+=m;
	}
	return sum;
}