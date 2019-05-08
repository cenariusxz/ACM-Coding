#include<stdio.h>
#include<string.h>
int main()
{
	int tran(char a[],int len),len,i,m=1;
	char a[10];
	printf("请输入一个由0~9构成的字符串.\n");		//提示用户输入
	gets(a);
	len=strlen(a);									//计算字符串长度
	for (i=0;i<=len-1;i++)							//先判断输入格式是否有误，有误则将m赋值为0，无误则为1
	{
		if (a[i]<48||a[i]>58)
		{
			m=0;
			break;
		}
	}
	if (m==0) printf("error!\n");					//输入有误则输出警告，否则输出转换结果
	else printf("转换后的结果:\n%d\n",tran(a,len));
	return 0;
}

int tran(char a[],int len)							//转换函数
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