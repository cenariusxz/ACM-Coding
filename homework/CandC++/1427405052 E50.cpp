#include<stdio.h>
#include<stdlib.h>

int main()
{
	char ch;
	FILE *fp1,*fp2,*out;
	fp1=fopen("1.txt","rb");
	fp2=fopen("2.txt","rb");
	out=fopen("out.txt","wb");
	if(fp1==NULL)					//���ļ��޷�������ʾ���رճ���
	{
		printf("�ļ��޷���.\n");
		exit(0);
	}
	if(fp2==NULL)
	{
		printf("�ļ��޷���.\n");
		exit(0);
	}
	while(!feof(fp1))				//�ֱ������ļ������ݸ��ƽ�out�ļ�
	{
		ch=fgetc(fp1);
		fputc(ch,out);
		putchar(ch);
	}
	printf("\n");
	while(!feof(fp2))
	{
		ch=fgetc(fp2);
		putchar(ch);
		fputc(ch,out);
	}
	printf("\n");
	fclose(fp1);					//�ر��ļ�
	fclose(fp2);
	fclose(out);
	return 0;
}