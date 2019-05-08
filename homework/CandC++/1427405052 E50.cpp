#include<stdio.h>
#include<stdlib.h>

int main()
{
	char ch;
	FILE *fp1,*fp2,*out;
	fp1=fopen("1.txt","rb");
	fp2=fopen("2.txt","rb");
	out=fopen("out.txt","wb");
	if(fp1==NULL)					//若文件无法打开则提示并关闭程序
	{
		printf("文件无法打开.\n");
		exit(0);
	}
	if(fp2==NULL)
	{
		printf("文件无法打开.\n");
		exit(0);
	}
	while(!feof(fp1))				//分别将两个文件的内容复制进out文件
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
	fclose(fp1);					//关闭文件
	fclose(fp2);
	fclose(out);
	return 0;
}