#include<stdio.h>
#include<string.h>
void calcu(char *);
int main()
{
	char a[6],*p;
	printf("�����������ֹ��ɵ�һ���ַ���(����С��5).\n");			//��ʾ�û�����
	scanf("%s",a);
	p=a;
	calcu(p);
	return 0;
}

void calcu(char *p)
{
	int max=0,min=0,i,j,t,len;
	int b[6];
	len=strlen(p);
	for (i=0;i<len;i++) b[i]=*(p+i)-48;								//������a���Ƶ�����b
	for (i=0;i<len;i++) for (j=i+1;j<len;j++) if (b[j]<b[i])		//������b��������
	{
		t=b[j];
		b[j]=b[i];
		b[i]=t;
	}
	for (i=len-1;i>=0;i--)											//������ɵ����ֵ
	{
		t=b[i];
		for (j=1;j<=i;j++) t*=10;
		max+=t;
	}
	printf("���ֵ��%d\n",max);
	if (b[0]==0) for (i=0;i<len;i++) if (b[i]!=0)					//�ų�0�ڿ�ͷ�������������ɵ���Сֵ
	{
		t=b[0];
		b[0]=b[i];
		b[i]=t;
		break;
	}
	for (i=0;i<len;i++)
	{
		t=b[i];
		for (j=1;j<=len-i-1;j++) t*=10;
		min+=t;
	}
	printf("��Сֵ��%d\n",min);
}