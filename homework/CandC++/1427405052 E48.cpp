#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *in,*out;
	char ch,inf[10],outf[10];
	printf("����������ļ������֣�");	//��ʾ�û������ļ���
	scanf("%s",inf);
	printf("����������ļ������֣�");
	scanf("%s",outf);
	if ((in=fopen(inf,"r"))==NULL)		//���ļ�����������ʾ���󲢽�������
	{
		printf("�޷��򿪴��ļ���\n");
		exit(0);
	}
	if ((out=fopen(outf,"w"))==NULL)
	{
		printf("�޷��򿪴��ļ���\n");
		exit(0);
	}
	while(!feof(in))					//�����ļ�����
	{
		ch=fgetc(in);
		fputc(ch,out);
		putchar(ch);
	}
	putchar(10);
	fclose(in);							//�ر��ļ�
	fclose(out);
	return 0;
}