#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *in,*out;
	char ch,inf[10],outf[10];
	printf("请输入读入文件的名字：");	//提示用户输入文件名
	scanf("%s",inf);
	printf("请输入输出文件的名字：");
	scanf("%s",outf);
	if ((in=fopen(inf,"r"))==NULL)		//若文件不存在则提示错误并结束程序
	{
		printf("无法打开此文件。\n");
		exit(0);
	}
	if ((out=fopen(outf,"w"))==NULL)
	{
		printf("无法打开此文件。\n");
		exit(0);
	}
	while(!feof(in))					//复制文件内容
	{
		ch=fgetc(in);
		fputc(ch,out);
		putchar(ch);
	}
	putchar(10);
	fclose(in);							//关闭文件
	fclose(out);
	return 0;
}